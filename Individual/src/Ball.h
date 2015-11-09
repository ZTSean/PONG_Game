/**
 * @file Ball.h
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The header file for Ball class.
 * 
 */


#ifndef BALL_H
#define BALL_H
#include <cmath>
#include <vector>
#include "Player.h"

#define BALL_RADIUS 15.0f
#define STEP_TIME 0.01f

/**
 * @brief enum type to represent wall in detecting collision.
 */
enum Wall{								
	None,
	Top,
	Bottom,
	Left,
	Right,
	TopPaddle,
	BottomPaddle
};

/**
 * @brief Ball class represents the ball in game.
 */
class Ball{
	public:
		/**
		 * @brief Default constructor.
		 * @param x The center x position of ball.
		 * @param y The center y position of ball.
		 * @param r The radius of ball.
		 * @param ori The orientation of ball.
		 * @param sp The speed of ball.
		 */
		Ball(float x, float y, float r, float ori, float sp);
		
		//-----------------------------mutator--------------------------------
		/**
		 * @brief Mutator to change the x position of the ball according to the input.
		 * @param newX The new X position value.
		 */
		void setXPosition(float newX);
		
		/**
		 * @brief Mutator to change the y position of the ball according to the input.
		 * @param newY The new y position value.
		 */
		void setYPosition(float newY);
		
		
		/*
		 * @brief Mutator to change the x position of the ball according to the input.
		 * @param newX The new X position value.
		 *
		void setZPosition(float newZ);*/
		
		/**
		 * @brief Mutator to change the radius of the ball according to the input.
		 * @param r The new radius value.
		 */
		void setRadius(float r);
		
		/**
		 * @brief set Ball's speed through arguement.
		 * @param sp Set Ball's speed according to arguement double sp.
		 */
		void setSpeed(float sp); // speed in pixels per second
		
		/**
		 * @brief Mutator to change the orientation of the ball according to the input.
		 * @param newX The new orientation value.
		 */
		void setOrientation(float ori);
		
		
		
		//-----------------------------accessor-------------------------------
		/**
		 * @brief Getter to get the x position of the ball.
		 */
		float getXPosition();
		
		/**
		 * @brief Getter to get the y position of the ball.
		 */
		float getYPosition();
		
		/*
		 * @brief Getter to get the z position of the ball.
		 *
		float getZPosition();*/
		
		/**
		 * @brief Getter to get the radius of the ball.
		 */
		float getRadius();
		
		/**
		 * @brief Getter to get the position of the ball.
		 */
		float getOrientation();
		
		/**
		 * @brief Getter to get the speed of the ball.
		 */
		float getSpeed();
		
		//-----------------------------functionality-------------------------------
		/**
		 * @brief Detect whether ball against the wall of window.
		 * @param width The witdth of window(default: 800)
		 * @param height The height of window(default: 800)
		 * @param p The vector of players' paddle.
		 * @param move The playing mode of the pong game.
		 */
		Wall detectWall(int witdth, int height, std::vector<Player> *p, int move);
		
		/**
		 * @brief Move the ball accoding to the step time.
		 * @param w The witdth of window(default: 800)
		 * @param h The height of window(default: 800)
		 * @param p The vector of players' paddle.
		 * @param mode The playing mode of the pong game.
		 */
		int move(int w, int h, std::vector<Player> *p, int mode);
		
		
	private:
		float radius;				/**< The radius of the ball*/
		float pos_x;				/**< The x position of the ball*/
		float pos_y;				/**< The y position of the ball*/
		//float pos_z;				/**< The z position of the ball*/
		float orientation;			/**< The orientation of the ball*/
		float speed;				/**< The speed of the ball*/
		

};


#endif
