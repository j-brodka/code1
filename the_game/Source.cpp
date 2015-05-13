#include <iostream>
#define PI 3.14159265
#include "func.h"
#include "NPC.h"
#include <GL/freeglut.h>
#include "imageloader.h"
#include "przeszkoda.h"
#include <vector>


int main(int argc, char *argv[])
{
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	zaladujObrazy();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	stworzKolizja();
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(SpecialKeysFunc);
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	
	glutMainLoop();


	return 0;
}