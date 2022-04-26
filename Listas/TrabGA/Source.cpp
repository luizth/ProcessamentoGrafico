#include <GL/glut.h>
#include <GL/gl.h>
#include "game.h"

#define COLS 40
#define ROWS 40

#define FPS 10

extern short snakeDir;
bool gameOver = false;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	initGrid(COLS, ROWS);
}

void display(void);
void reshape(int, int);
void timer(int);
void keyboard(int, int, int);

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(600, 600);

	glutInitWindowPosition(100, 100);

	glutCreateWindow("Snake Game");

	init();

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutTimerFunc(0, timer, 0);

	glutSpecialFunc(keyboard);

	glutMainLoop();

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawGrid();

	drawSnake();

	drawFood();

	glutSwapBuffers();

	if (gameOver)
	{
		MessageBox(NULL, (LPCWSTR) "Game Over!", (LPCWSTR) "Game Over", 0);
		exit(0); 
	}

	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.50, 0.75, 0.0);
	glEnd();

	glFlush();
	*/
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLS, 0.0, ROWS, -1.0, 1.0);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/FPS, timer, 0);
}

void keyboard(int key, int, int)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (snakeDir != DOWN)
			snakeDir = UP;
		break;

	case GLUT_KEY_DOWN:
		if (snakeDir != UP)
			snakeDir = DOWN;
		break;

	case GLUT_KEY_RIGHT:
		if (snakeDir != LEFT)
			snakeDir = RIGHT;
		break;

	case GLUT_KEY_LEFT:
		if (snakeDir != RIGHT)
			snakeDir = LEFT;
		break;
	}
}
