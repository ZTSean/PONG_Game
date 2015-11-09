
/**
 * @file Simulation.h
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief Main application class for the robot simulation
 * 
 */



#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <cstdlib>
#include "BaseGfxApp.h"
#include "PongGame.h"

/**
 * @brief The Simulation class.  This sets up the GUI and the drawing environment.
 */
class Simulation : public BaseGfxApp {
public: 
	/**
	 * @brief the type of UI Control input.
	 */
	enum UIControlType {
		UI_QUIT = 0,
		UI_RESUME = 4,
		UI_PAUSE = 3,
		UI_PRACTICE = 1,
		UI_2PLAYER = 2,
		UI_SPIN = 5
	};
	
	/**
	 * @brief arguements from user's command input and other window information. 
	 * @param argc The number of command arguement.
	 * @param argv The command input array.
	 * @param width The width of window.
	 * @param height The height of window.
	 */
	Simulation(int argc, char* argv[], int width, int height);
	
	/**
	 * @brief Default constructor.
	 */
	virtual ~Simulation();

	/**
	 * @brief display all the items.
	 */
	void display();    
	
	/**
	 * @brief Control panel through input control id.
	 * @param controlID The ID for control behavoir.
	 */
	void gluiControl(int controlID);
	
	//---------------------------------------render function---------------------------------
	/**
	 * @brief draw ball and send them to the window.  
	 * @param b pass in the ball which is to be sent. 
	 */
	void renderBall(Ball b);
	
	/**
	 * @brief draw player and send them to the window.  
	 * @param p pass in the player which is to be sent. 
	 */
	void renderPlayer(Player p);
	
	/**
	 * @brief draw socre and send them to the window.  
	 */
	void renderScore();
	
	
	//-----------------------------------mouse control function----------------------------------
	/**
	 * @brief The action will be taken when left mouse is clicked.
	 * @param x the x position of mouse click position.
	 * @param y the y position of mouse click position.
	 */
	void leftMouseDown(int x, int y);
	
	/**
	 * @brief The action will be taken when left mouse is released.
	 * @param x the x position of mouse click position.
	 * @param y the y position of mouse click position.
	 */
	void leftMouseUp(int x, int y);
	


	/**
	 * @brief detect whether there is any overlap between robot, two obstacles and target.
	 */
	void detectcollision();
	
	//---------------------------keyboard control function-----------------------------------
	/**
	 * @brief Control the paddle through key input.
	 * @param c The key input to control the panel.
	 * @param x The x position of mouse click position.
	 * @param y The y position of mouse click position.
	 */
	void keyboard(unsigned char c, int x, int y);
	
	/**
	 * @brief Control the paddle through special input.
	 * @param key The special key input to control panel.
	 * @param x The x position of mouse click position.
	 * @param y The y position of mouse click position.
	 */
	void keyboardSpecial(int key, int x, int y);

	


private:
	
	bool controlflag;					/**< The flag for panel input*/
	int numBall;						/**< The number of ball*/
	int numPlayer;						/**< The number of player*/
	double oldTimeSinceStart;			/**< The time since the start*/
	vector<Ball> balls;					/**< A vector of balls created*/
	vector<Player> players;				/**< A vector of players created*/
	PongGame* env;						/**< A environment created*/
	GLUI_Spinner* spinner;				/**< A panel spinner*/
	int mode;							/**< The Play mode of the game*/
	

};


#endif
