/**
 * @file PongGame.h
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The header file for PongGame class.
 * 
 */

#ifndef PONGGAME_H
#define PONGGAME_H

#include <cmath>
#include <vector>
#include "Ball.h"
#include "Player.h"
#include <time.h>

/**
 * @brief The PongGame class.  This class represents game environment.
 */
class PongGame{
	public:
		/**
		 * @brief Constructor.
		 * @param width The width of window.
		 * @param height The height of window.
		 * @param b The balls in the game.
		 * @param p The players in the game.
		 */
		PongGame(int width, int height, std::vector<Ball> *b, std::vector<Player> *p);
		
		/**
		 * @brief Default Constructor.
		 */
		~PongGame();
		
		
		/**
		 * @brief Update the status of game by the specificied amount time.
		 * @param elaspedTime The delta time.
		 */
		int updateMove();
		
		
		
		/**
		 * @brief Balls register with the environment, which adds them to the environment data structure(s).
		 * @param b the ball need to be registered to the environment.
		 */
		void registerBall(Ball b);
		
		/**
		 * @brief Players register with the environment, which adds them to the environment data structure(s).
		 * @param p the player need to be registered to the environment.
		 */
		void registerPlayer(Player p);
		
		/**
		 * @brief Start a new Game.
		 */
		void StartNewGame();
		
		//---------------------------------accessor---------------------------------
		/**
		 * @brief Getter to get the start time of the game.
		 */
		time_t getStartTime();
		
		/**
		 * @brief Getter to get the how long does game last.
		 */
		double getDifftime();
		
		/**
		 * @brief Getter to get the specific score according to the input index.
		 * @param i The index of the specific score.
		 */
		int getScorei(int i);
		
		/**
		 * @brief Getter to get the mode of game.
		 */
		int getMode();
		
		//---------------------------------mutator---------------------------------
		/**
		 * @brief Mutator to change the start time of the game.
		 * @param newTime The start time of the game.
		 */
		void setStartTime(time_t newTime);
		
		/**
		 * @brief Mutator to change the mode of the game.
		 * @param i The mode of the game.
		 */
		void setMode(int i);
		
		/**
		 * @brief Mutator to change lasting time of the game.
		 * @param newdiffTime The lasting time of the game.
		 */
		void setDifftime(double newdiffTime);
		
	private:
		int numBall;						/**< The number of ball*/
		int numPlayer;						/**< The number of player*/
		int scores[2];						/**< The score of two player*/
		int width;							/**< The width of window*/
		int height;							/**< The height of window*/
		std::vector<Player> *players;		/**< The players*/
		std::vector<Ball> *balls;			/**< The balls*/
		int mode;							/**< The play mode of game*/
		time_t start_time;					/**< The start time of the game*/
		double seconds_since_start;			/**< The diff time since game start*/
		
	


};


#endif
