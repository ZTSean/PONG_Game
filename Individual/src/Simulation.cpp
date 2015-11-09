/**
 * @file Simulation.cpp
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The simulation of pong game.
 * 
 */

#include "Simulation.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

/**
 * @brief arguements from user's command input and other window information. 
 * @param argc The number of command arguement.
 * @param argv The command input array.
 * @param width The width of window.
 * @param height The height of window.
 */
Simulation::Simulation(int argc, char* argv[], int width, int height) : BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

	//creates a basic UI panel with quit button
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");
	new GLUI_Button(m_glui, "Practice Mode", UI_PRACTICE, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "2-Player Mode", UI_2PLAYER, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Pause", UI_PAUSE, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Resume", UI_RESUME, (GLUI_Update_CB)s_gluicallback);
	new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)quick_exit);
	int scale = 1;
	//add_spinner_to_panel( GLUI_Panel *panel, const char *name, int data_type=GLUI_SPINNER_INT, void *live_var=NULL, int id=-1, GLUI_CB callback=GLUI_CB() );
	spinner = m_glui->add_spinner_to_panel(toolPanel, "Level(1-3):", GLUI_SPINNER_INT, &scale, UI_SPIN, (GLUI_Update_CB)s_gluicallback);
	spinner->set_int_limits(1, 3, GLUI_LIMIT_CLAMP);
	
	
	// Initialize OpenGL
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluOrtho2D(0, m_width, 0, m_height);
	glViewport(0, 0, m_width, m_height);
	
	controlflag = true;
	env = new PongGame(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), &balls, &players);
	oldTimeSinceStart = 0;
	
	// environment construct
	//env.PongGame((glutGet(GLUT_WINDOW_WIDTH)*glutGet(GLUT_WINDOW_HEIGHT)), glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), &physicalObjects);
	
	// initial setting : 2 players, 1 ball
	srand(time(NULL));
	
	int i = 0;
	numBall = 1;
	numPlayer = 2; 
	
	for (i = 0; i < numBall; i++)
	{
		Ball ball(400, 400, BALL_RADIUS, fmod((double)rand(), 2*M_PI), 50);
		env->registerBall(ball);
		cout << "Ball created"<< endl;
	}
	
	Player player1(400, 800, 10, 100, 0, 0);
	env->registerPlayer(player1);
	cout << "Player 1 created: " << player1.getXPosition() << " " << player1.getYPosition() << endl;
	
	Player player2(400, 0, 10, 100, 0, 0);
	env->registerPlayer(player2);
	cout << "Player 2 created: " << player2.getXPosition() << " " << player2.getYPosition() << endl;
	
	/*
	cout << "avoid initial overlap start:"<<endl;
	// avoid initial overlap
	int num = numBall + numPlayer;	
	for (i = 0; i < num; i++){
		for ( j = i; j < num; j++){
			if( (j != i) && (physicalObjects[i].detectObstacle(physicalObjects[j]) || physicalObjects[i].detectWall(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT))))
			{
				//cout << "overlapped!!" <<endl;
				int r = physicalObjects[i].getSize();
				physicalObjects[i].setPosition(rand() % (800-2*r) + r, rand() % (800-2*r)+r);	// if overlap reset a new position until no overlap
				j = 0;
			}
		}
	}*/

}

/**
 * @brief Control panel through input control id.
 * @param n The ID for control behavoir.
 */
void Simulation::gluiControl(int n)
{
	switch(n)
	{
		case 1:				// mode 1 and start game
			mode = 1;
			env->setMode(1);
			env->StartNewGame();
			controlflag = false;
			break;
		case 2:				// mode 2 and start game
			env->setMode(2);
			env->StartNewGame();
			mode = 2;
			controlflag = false;
			break;
		case 3:			// pause
			controlflag = true;
			break;
		case 4:			// resume
			controlflag = false;
			break;
		case 5:			// control the hard level of game
			int i = 0;
			int k = spinner->get_int_val();
			if (k == 1)
			{
				k = 50;
			}else if(k == 2)
			{
				k = 200;
			}else if (k == 3)
			{
				k = 400;
			}
			for (i = 0; i < numBall; i++)
			{
				balls[i].setSpeed((double)k);
			}
			break;
	}
}

/**
 * @brief display all the items.
 */
void Simulation::display()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	int i = 0;
	
	/*
	double timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	if (oldTimeSinceStart == 0.0)
	{
		oldTimeSinceStart = timeSinceStart;
	}
	
	double deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;*/
		
	// update all 
	if (!controlflag){
		int temp = env->updateMove();
		if (temp == 1)
		{
			controlflag = true;
		}
	}
	
	//render all balls
	for (i = 0; i < numBall; i++){ 
		renderBall(balls[i]);
	}
	
	//render player accoding to mode

		renderPlayer(players[0]);
		renderPlayer(players[1]);
	

	renderScore();
	
	// debugging messages
	int err;
	if ((err = glGetError()) != GL_NO_ERROR) {
		cerr << "GL is in an error state" << endl;
		cerr << "(GL error code " << err << ")\n";
		assert(0);
	}

	// advance
	glutSwapBuffers();
}


/**
 * @brief Default constructor.
 */
Simulation::~Simulation()
{
	delete env;
}

/**
 * @brief The action will be taken when left mouse is clicked.
 * @param x the x position of mouse click position.
 * @param y the y position of mouse click position.
 */
void Simulation::leftMouseDown(int x, int y)
{
	controlflag = !controlflag;
}

/**
 * @brief The action will be taken when left mouse is released.
 * @param x the x position of mouse click position.
 * @param y the y position of mouse click position.
 */
void Simulation::leftMouseUp(int x, int y)
{
	// nohing here for now
}

//----------------------------------Render function--------------------------------
/**
 * @brief draw player and send them to the window.  
 * @param p pass in the player which is to be sent. 
 */
void Simulation::renderPlayer(Player p){
	
	
	float half_width = p.getWidth()/2.0;
	float half_length = p.getLength()/2.0;
	
	glPushMatrix();
	glTranslatef(p.getXPosition(), p.getYPosition(), 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	
		glVertex2f(-half_width, half_length);
		glVertex2f(half_width, half_length);
		glVertex2f(half_width, -half_length);
		glVertex2f(-half_width, -half_length);
	
	glEnd();
	glPopMatrix();
}

/**
 * @brief draw ball and send them to the window.  
 * @param b pass in the ball which is to be sent. 
 */
void Simulation::renderBall(Ball b){
	int i = 0;
	glPushMatrix();
	glTranslatef(b.getXPosition(), b.getYPosition(), 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i <= 50; i++){
		glVertex2f(
			(b.getRadius() *cos (i * 2.0 * M_PI/50)),
			(b.getRadius() *sin (i * 2.0 * M_PI/50))
		);
	}
	glEnd();
	glPopMatrix();
	
	
}

/**
 * @brief draw socre and send them to the window.  
 */
void Simulation::renderScore()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	char buffer[100];
	if (mode == 1)
	{
		int sec = (int)env->getDifftime();
		int m = sec/60;
		int r = sec%60;
		sprintf(buffer, "Time(miniute:seconds): %d : %d", m, r);
	}else if(mode == 2)
	{
		sprintf(buffer, "Player1:Player2  =  %d : %d\0", env->getScorei(0), env->getScorei(1));
	}
	
	glRasterPos2i(5, 20);
	unsigned int i = 0;
	for (i = 0; i < strlen (buffer); i++)
    {
		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, buffer[i]);
	}
}

//-------------------------------------keyboard control function-------------------------
/**
 * @brief Control the paddle through key input.
 * @param c The key input to control the panel.
 * @param x The x position of mouse click position.
 * @param y The y position of mouse click position.
 */
void Simulation::keyboard(unsigned char key, int x, int y) 
{
	double k = 0;
	if (!controlflag){
		switch (key)
		{
			
			case 'a':
				k = players[0].getXPosition() - 10;
				if(players[0].getXPosition() - 10 - players[0].getWidth()/2 < 0)
				{
					k = players[0].getWidth()/2;
				}
				players[0].setXPosition(k);
				break;
			case 'd':
				k = players[0].getXPosition() + 10;
				if(players[0].getXPosition() + 10 + players[0].getWidth()/2 > 800)
				{
					k = 800 - players[0].getWidth()/2;
				}
				players[0].setXPosition(k);
				break;
		}
	}
}

/**
 * @brief Control the paddle through special input.
 * @param key The special key input to control panel.
 * @param x The x position of mouse click position.
 * @param y The y position of mouse click position.
 */
void Simulation::keyboardSpecial(int key, int x, int y)
{
	double k = 0;
	if (!controlflag)
	{
		switch (key)
		{
			case GLUT_KEY_LEFT:
				k = players[1].getXPosition() - 10;
				if(players[1].getXPosition() - 10 - players[1].getWidth()/2 < 0)
				{
					k = players[1].getWidth()/2;
				}
				players[1].setXPosition(k);
				break;
			case GLUT_KEY_RIGHT:
				k = players[1].getXPosition() + 10;
				if(players[1].getXPosition() + 10 + players[1].getWidth()/2 > 800)
				{
					k = 800 - players[1].getWidth()/2;
				}
				players[1].setXPosition(k);
				break;
		}
	}
}


