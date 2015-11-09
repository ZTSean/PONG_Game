/**
 * @file PongGame.cpp
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The detail implementation for PongGame class.
 * 
 */
 
#include "PongGame.h"
/**
 * @brief Constructor.
 * @param width The width of window.
 * @param height The height of window.
 * @param b The balls in the game.
 * @param p The players in the game.
 */
PongGame::PongGame(int w, int h, std::vector<Ball> *b, std::vector<Player> *p)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		scores[i] = 0;
	}
	
	numBall = 0;
	numPlayer = 0;
	
	players = p;
	balls = b;
	
	width = w;
	height = h;
	
	mode = 1;
}

/**
 * @brief Default Constructor.
 */
PongGame::~PongGame()
{
	
}


//-----------------------------Funcionality-------------------------------
/**
 * @brief Start a new Game.
 */
void PongGame::StartNewGame()
{
	int i = 0;
	for (i = 0; i < numBall; i++)
	{
		(*balls)[i].setXPosition(400);
		(*balls)[i].setYPosition(400);
	}
	start_time = time(0);
}

/**
 * @brief Update the status of game by the specificied amount time.
 * @param elaspedTime The delta time.
 */
int PongGame::updateMove()
{
	int i = 0;
	for (i = 0; i < numPlayer; i++)
	{
		(*players)[i].move(width, height);
	}
	
	seconds_since_start = difftime(time(0), start_time);
	
	for (i = 0; i < numBall; i++) 
	{
		int k = 0;
		k = (*balls)[i].move(width, height, players, mode);
		if (k == 1)
		{
			scores[0] += 1;
			StartNewGame();
			return 1;				// start new game, stop update
		}else if(k == 2)
		{
			scores[1] += 1;
			StartNewGame();
			return 1;				// start new game, stop update
		}
		
		// make practice paddle follow the ball
		if (mode == 1)
		{
			(*players)[0].setXPosition(((*balls)[i].getXPosition()));
		}
	}
	
	return 0;
}

/**
 * @brief Balls register with the environment, which adds them to the environment data structure(s).
 * @param b the ball need to be registered to the environment.
 */
void PongGame::registerBall(Ball b){
	balls->push_back(b);
	numBall++;
}

/**
 * @brief Players register with the environment, which adds them to the environment data structure(s).
 * @param p the player need to be registered to the environment.
 */
void PongGame::registerPlayer(Player p){
	players->push_back(p);
	numPlayer++;
}

//-----------------------------accessor-------------------------------
/**
 * @brief Getter to get the specific score according to the input index.
 * @param i The index of the specific score.
 */
int PongGame::getScorei(int i)
{
	return scores[i];
}

/**
 * @brief Getter to get the mode of game.
 */
int PongGame::getMode()
{
	return mode;
}

/**
 * @brief Getter to get the start time of the game.
 */
time_t PongGame::getStartTime()
{
	return start_time;
}

/**
 * @brief Getter to get the how long does game last.
 */
double PongGame::getDifftime()
{
	return seconds_since_start;
}

//-----------------------------mutator-------------------------------
/**
 * @brief Mutator to change the mode of the game.
 * @param i The mode of the game.
 */
void PongGame::setMode(int i)
{
	mode = i;
}

/**
 * @brief Mutator to change the start time of the game.
 * @param newTime The start time of the game.
 */
void PongGame::setStartTime(time_t newTime)
{
	start_time = newTime;
}

/**
 * @brief Mutator to change lasting time of the game.
 * @param newdiffTime The lasting time of the game.
 */
void PongGame::setDifftime(double newdiffTime)
{
	seconds_since_start = newdiffTime;
}
