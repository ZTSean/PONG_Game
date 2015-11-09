/**
 * @file Simulation.h
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The header file for Simulation of pong game.
 * 
 */


#ifndef SIMULATION_H
#define SIMULATION_H

class PongGame;

class Simlation {
	public:
		
		/**
		 * @brief Default constructor.
		 */
		Simulation();
		
		~Simulation();
		
		void drawPlayers();
		
		void drawBalls();
		
		void 
		
		void StartNewGame();
		
		void initSimulation();
		
	private:
		PongGame* GameEnv;
	
	
}

#endif
