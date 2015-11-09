/**
 * @file Ball.cpp
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The detail implementation for Ball class.
 * 
 */

#include "Ball.h"
#include <exception>
#include <iostream>
using namespace std;

//-----------------------------helper function--------------------------------
/**
 * @brief Helper function to regulate the orientation.
 * @param ori The orientation value need to be set to 0 - 2PI.
 */
double regular_ori(double ori)
{
	while (ori > 2*M_PI)
	{
		ori -= 2*M_PI;
	}
	
	while (ori < 0)
	{
		ori += 2* M_PI;
	}
	
	return ori;
}


//-----------------------------constructor--------------------------------
/**
 * @brief Default constructor.
 * @param x The center x position of ball.
 * @param y The center y position of ball.
 * @param r The radius of ball.
 * @param ori The orientation of ball.
 * @param sp The speed of ball.
 */
Ball::Ball(float x, float y, float r, float ori, float sp)
{
	radius = r;
	pos_x = x;
	pos_y = y;
	//pos_z = z;
	orientation = ori;
	speed = sp;
}


//-----------------------------mutator--------------------------------
/**
 * @brief Mutator to change the x position of the ball according to the input.
 * @param newX The new X position value.
 */
void Ball::setXPosition(float newX)
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
void Ball::setZPosition(float newZ)
{
	if (newZ < 0 || newZ > 800)
	{
		
	}else
	{
		pos_z = newZ;
	}
}*/

/**
 * @brief Mutator to change the y position of the ball according to the input.
 * @param newY The new y position value.
 */
void Ball::setYPosition(float newY)
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
 * @brief Mutator to change the radius of the ball according to the input.
 * @param r The new radius value.
 */
void Ball::setRadius(float r)
{
	try 
	{
		if (r < 0.0 )
		{
			throw -1;
		}
	}catch(int e)
	{
		if (e == -1)
		{
			cout << "The input new radius should not be less than 0." << endl;
		}
	}
	
	radius = r;
}

/**
 * @brief set Ball's speed through arguement.
 * @param sp Set Ball's speed according to arguement double sp.
 */
void Ball::setOrientation(float ori)
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
 * @brief Mutator to change the orientation of the ball according to the input.
 * @param newX The new orientation value.
 */
void Ball::setSpeed(float sp)
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
 * @brief Getter to get the x position of the ball.
 */
float Ball::getXPosition()
{
	return pos_x;
}

/**
 * @brief Getter to get the y position of the ball.
 */
float Ball::getYPosition()
{
	return pos_y;
}

/*
float Ball::getZPosition()
{
	return pos_z;
}*/

/**
 * @brief Getter to get the radius of the ball.
 */
float Ball::getRadius()
{
	return radius;
}

/**
 * @brief Getter to get the position of the ball.
 */
float Ball::getOrientation()
{
	return orientation;
}

/**
 * @brief Getter to get the speed of the ball.
 */
float Ball::getSpeed()
{
	return speed;
}

//-----------------------------FUNCTIONALITY-------------------------------
/**
 * @brief Detect whether ball against the wall of window.
 * @param width The witdth of window(default: 800)
 * @param height The height of window(default: 800)
 * @param p The vector of players' paddle.
 * @param move The playing mode of the pong game.
 */
Wall Ball::detectWall(int w, int h, vector<Player> *p, int mode)
{

		if ( (pos_x + radius) >= w )
		{
			return Right;
		}else if( pos_x <= radius)
		{
			return Left;
		}
		else if ( (pos_y + radius) >= h)
		{
			return Top;
		}else if (pos_y <= radius)
		{
			return Bottom;
		}else if(((*p)[0].getYPosition()-(*p)[0].getLength()/2.0 < radius + pos_y) && ((*p)[0].getXPosition()-(*p)[0].getWidth()/2.0 < pos_x - radius) && ((*p)[0].getXPosition()+(*p)[0].getWidth()/2.0 > pos_x + radius))
		{
			return TopPaddle;
		}else if(((*p)[1].getYPosition()+(*p)[1].getLength()/2.0 > pos_y-radius) && ((*p)[1].getXPosition()-(*p)[1].getWidth()/2.0 < pos_x - radius) && ((*p)[1].getXPosition()+(*p)[1].getWidth()/2.0 > pos_x + radius))
		{
			return BottomPaddle;
		}else
		{
			return None;
		}


}

/**
 * @brief Move the ball accoding to the step time.
 * @param w The witdth of window(default: 800)
 * @param h The height of window(default: 800)
 * @param p The vector of players' paddle.
 * @param mode The playing mode of the pong game.
 */
int Ball::move(int w, int h, vector<Player> *p, int mode)
{
	pos_x += speed * STEP_TIME * cos(orientation);
	pos_y += speed * STEP_TIME * sin(orientation);
	
	
	if (detectWall(w, h, p, mode) == Left)
	{
		if (orientation > M_PI){							// collision with left wall 
			//orientation += M_PI/2;
			orientation = regular_ori(3*M_PI - orientation);
		}else{
			//orientation -= M_PI/2;
			orientation = regular_ori(M_PI - orientation);
		}
	}else if (detectWall(w, h, p, mode) == Right)
	{
		if (orientation < M_PI/2){							// collision with right wall
			//orientation += M_PI/2;
			orientation = regular_ori(M_PI - orientation);
		}else{
			//orientation -= M_PI/2;
			orientation = regular_ori(3*M_PI - orientation);
		}
	}else if (detectWall(w, h, p, mode) == TopPaddle) 
	{
		if (orientation > M_PI/2){							// collision with top Paddle
			//orientation += M_PI/2;
			orientation = regular_ori(2*M_PI - orientation);
		}else{
			//orientation += 3*M_PI/2;
			orientation = regular_ori(2*M_PI - orientation);
		}
	}else if (detectWall(w, h, p, mode) == BottomPaddle)
	{
		if (orientation > 3*M_PI/2){			// collision with bottom Paddle
			//orientation -= 3*M_PI/2;
			orientation = regular_ori(2*M_PI - orientation);
		}else{
			//orientation -= M_PI/2;
			orientation = regular_ori(2*M_PI - orientation);
		}
	}else if (detectWall(w, h, p, mode) == Bottom)				// player 1 wins
	{
		return 1;
	}else if(detectWall(w, h, p, mode) == Top)					// player 2 wins
	{
		return 2;
	}
	
	return 0;				// no one wins
}
