/**
 * @file main.cpp
 * @author Zixiao Wang
 * @date 7 May 2015
 * @brief The main file of pong game.
 * 
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "gamedrawer.h"

using namespace std;



//The number of milliseconds between calls to update
const int TIMER_MS = 25;

GameDrawer* gameDrawer;

//Starts at 0, then increases until it reaches 2 * PI, then jumps back to 0 and
//repeats.  Used to have the camera angle slowly change.
float rotationVar = 0;


void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	initGameDrawer();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.5f, -0.3f, -1.8f);
	glRotatef(50, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	
	//This makes the camera rotate slowly over time
	glTranslatef(0.5f, 0, 0.5f);
	glRotatef(3 * sin(rotationVar), 0, 1, 0);
	glTranslatef(-0.5f, 0, -0.5f);
	
	gameDrawer->draw();
	
	glutSwapBuffers();
}

void update(int value) {
	gameDrawer->advance((float)TIMER_MS / 1000);
	
	rotationVar += 0.2f * (float)TIMER_MS / 1000;
	while (rotationVar > 2 * PI) {
		rotationVar -= 2 * PI;
	}
	
	glutPostRedisplay();
	glutTimerFunc(TIMER_MS, update, 0);
}

int main(int argc, char** argv) {
	srand((unsigned int)time(0)); //Seed the random number generator
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	
	glutCreateWindow("Pong Game-Zixiao Wang");
	initRendering();
	
	gameDrawer = new GameDrawer();
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleSpecialKeypress);
	glutSpecialUpFunc(handleSpecialKeyReleased);
	glutReshapeFunc(handleResize);
	glutTimerFunc(TIMER_MS, update, 0);
	
	glutMainLoop();
	return 0;
}









