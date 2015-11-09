/**
 * @file Player.h
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The header file for player class.
 * 
 */
 
#ifndef PLAYER_H
#define PLAYER_H
#include <cmath>
#define STEP_TIME 0.01f

/**
 * @brief The Player class.  This sets up player and paddle.
 */
class Player
{
	public:
		/**
		 * @brief Constructor.
		 * @param x The center x position of paddle.
		 * @param y The center y position of paddle.
		 * @param l The length of paddle.
		 * @param w The width of paddle.
		 * @param ori The orientation of paddle.
		 * @param sp The speed of paddle.
		 */
		Player(float x, float y, float l, float w, float ori, float sp);
		
		/**
		 * @brief Default Constructor.
		 */
		~Player();
		
		//-----------------------------mutator--------------------------------
		/**
		 * @brief Mutator to change the x position of the paddle according to the input.
		 * @param newX The new X position value.
		 */
		void setXPosition(float newX);
		
		/**
		 * @brief Mutator to change the x position of the paddle according to the input.
		 * @param newX The new X position value.
		 */
		void setYPosition(float newY);
		
		/*
		 * @brief Mutator to change the x position of the paddle according to the input.
		 * @param newX The new X position value.
		 *
		void setZPosition(float newZ);*/
		
		/**
		 * @brief Mutator to change the length of the paddle according to the input.
		 * @param l The new length value.
		 */
		void setLength(float l);
		
		/**
		 * @brief Mutator to change the width of the paddle according to the input.
		 * @param l The new length value.
		 */
		void setWidth(float w);
		
		/**
		 * @brief set paddle's speed through arguement.
		 * @param sp Set paddle's speed according to arguement double sp.
		 */
		void setSpeed(float sp); // speed in pixels per second
		
		/**
		 * @brief Mutator to change the orientation of the paddle according to the input.
		 * @param newX The new orientation value.
		 */
		void setOrientation(float ori);
		
		
		//-----------------------------accessor-------------------------------
		/**
		 * @brief Getter to get the x position of the paddle.
		 */
		float getXPosition();
		
		/**
		 * @brief Getter to get the y position of the paddle.
		 */
		float getYPosition();
		
		/*
		 * @brief Getter to get the z position of the paddle.
		 *
		float getZPosition();*/
		
		/**
		 * @brief Getter to get the Length of the paddle.
		 */
		float getLength();
		
		/**
		 * @brief Getter to get the Width of the paddle.
		 */
		float getWidth();
		
		/**
		 * @brief Getter to get the position of the paddle.
		 */
		float getOrientation();
		
		/**
		 * @brief Getter to get the speed of the paddle.
		 */
		float getSpeed();
		
		//-----------------------------funcitonality-------------------------------
		/**
		 * @brief Move the Paddle accoding to the step time and speed.
		 * @param w The witdth of window(default: 800)
		 * @param h The height of window(default: 800)
		 */
		void move(int w, int h);
		
		
	private:
		float maxSpeed;				/**< The absolute maximum speed of the paddle*/
		float pos_x;				/**< The x position of the paddle*/
		float pos_y;				/**< The y position of the paddle*/
		//float pos_z;				/**< The z position of the paddle*/
		float speed;				/**< The speed of the paddle*/
		float length;				/**< The length of the paddle*/
		float width;				/**< The width of the paddle*/
		int orientation;			/**< The orientation of the paddle, -1 represents left, 1 represents right*/
};

#endif
