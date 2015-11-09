/**
 * @file Player.cpp
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The detail implementation for Player class.
 * 
 */


#include "Player.h"
#include <iostream>
#include <exception>
using namespace std;


//-----------------------------constructor--------------------------------
/**
 * @brief Constructor.
 * @param x The center x position of paddle.
 * @param y The center y position of paddle.
 * @param l The length of paddle.
 * @param w The width of paddle.
 * @param ori The orientation of paddle.
 * @param sp The speed of paddle.
 */
Player::Player(float x, float y, float l, float w, float ori, float sp)
{
	pos_x = x;
	pos_y = y;
	//pos_z = z;
	length = l;
	width = w;
	orientation = ori;
	speed = sp;
}

/**
 * @brief Default Constructor.
 */
Player::~Player()
{
	
}

//-----------------------------mutator--------------------------------
/**
 * @brief Mutator to change the x position of the paddle according to the input.
 * @param newX The new X position value.
 */
void Player::setXPosition(float newX)
{
	try 
	{
		if (newX < 0.0 )
		{
			throw -1;
		}else if (newX > 800.0)
		{
			throw -2;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input nex x position should not be less than 0." << endl;
		}else if (e == -2)
		{
			cout << "The input nex x position should not be greater than 800." << endl;
		}
	}
	
	pos_x = newX;
}

/*
void Player::setZPosition(float newZ)
{
	if (newZ < 0 || newZ > 800)
	{
		
	}else
	{
		pos_z = newZ;
	}
}*/

/**
 * @brief Mutator to change the x position of the paddle according to the input.
 * @param newX The new X position value.
 */
void Player::setYPosition(float newY)
{
	try 
	{
		if (newY < 0.0 )
		{
			throw -1;
		}else if (newY > 800.0)
		{
			throw -2;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input nex y position should not be less than 0." << endl;
		}else if (e == -2)
		{
			cout << "The input nex y position should not be greater than 800." << endl;
		}
	}
	
	pos_y = newY;
}

/**
 * @brief Mutator to change the length of the paddle according to the input.
 * @param l The new length value.
 */
void Player::setLength(float l)
{
	try 
	{
		if (l < 0.0 )
		{
			throw -1;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input new length should not be less than 0." << endl;
		}
	}
	
	length = l;
}

/**
 * @brief Mutator to change the width of the paddle according to the input.
 * @param l The new length value.
 */
void Player::setWidth(float w)
{
	try 
	{
		if (w < 0.0 )
		{
			throw -1;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input new width should not be less than 0." << endl;
		}
	}
	
	width = w;
}

/**
 * @brief Mutator to change the orientation of the paddle according to the input.
 * @param newX The new orientation value.
 */
void Player::setOrientation(float ori)
{
	try 
	{
		if (ori < 0.0 )
		{
			throw -1;
		}else if (ori > 2*M_PI)
		{
			throw -2;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input nex orientation should not be less than 0." << endl;
		}else if (e == -2)
		{
			cout << "The input nex orientation should not be greater than 2*PI." << endl;
		}
	}
	
	orientation = ori;
}

/**
 * @brief set paddle's speed through arguement.
 * @param sp Set paddle's speed according to arguement double sp.
 */
void Player::setSpeed(float sp)
{
	try 
	{
		if (sp < 0.0 )
		{
			throw -1;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input new speed should not be less than 0." << endl;
		}
	}
	speed = sp;
}

//-----------------------------accessor-------------------------------
/**
 * @brief Getter to get the x position of the paddle.
 */
float Player::getXPosition()
{
	return pos_x;
}

/**
 * @brief Getter to get the y position of the paddle.
 */
float Player::getYPosition()
{
	return pos_y;
}

/*
float Player::getZPosition()
{
	return pos_z;
}*/

/**
 * @brief Getter to get the Length of the paddle.
 */
float Player::getLength()
{
	return length;
}

/**
 * @brief Getter to get the Width of the paddle.
 */
float Player::getWidth()
{
	return width;
}

/**
 * @brief Getter to get the position of the paddle.
 */
float Player::getOrientation()
{
	return orientation;
}

/**
 * @brief Getter to get the speed of the paddle.
 */
float Player::getSpeed()
{
	return speed;
}


//-----------------------------Funcionality-------------------------------
/**
 * @brief Move the Paddle accoding to the step time and speed.
 * @param w The witdth of window(default: 800)
 * @param h The height of window(default: 800)
 */
void Player::move(int w, int h){
	double newX = speed* STEP_TIME + pos_x;
	if (newX - length/2 > 0 && newX + length/2 < w)
	{
		pos_x = newX;
	}
}
