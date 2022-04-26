#include <ctime>

#include <GL/glut.h>
#include <GL/gl.h>
#include "Game.h";


int gridX, gridY;
extern bool gameOver;

short snakeDir = RIGHT;
int snakeSize = 5;
int posSnakeX[60] = { 20, 20, 20, 20, 20 };
int posSnakeY[60] = { 20, 19, 18, 17, 16 };

bool food = true;
int posFoodX, posFoodY;


void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

void drawGrid()
{
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
		{
			drawUnit(i, j);
		}
	}

	drawUnit(20, 20);
}

void drawUnit(int x, int y)
{
	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1)
	{
		glLineWidth(2.0);
		glColor3f(1.0, 0.4, 0.4);
	}
	else
	{
		glLineWidth(0.5);
		glColor3f(0.8, 0.8, 0.8);
	}

	glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x+1, y);
		glVertex2f(x+1, y+1);
		glVertex2f(x, y+1);
	glEnd();
}

void drawSnake()
{
	// move
	for (int i = snakeSize - 1; i > 0; i--)
	{
		posSnakeX[i] = posSnakeX[i - 1];
		posSnakeY[i] = posSnakeY[i - 1];
	}

	if (snakeDir == UP)
		posSnakeY[0]++;
	else if (snakeDir == DOWN)
		posSnakeY[0]--;
	else if (snakeDir == RIGHT)
		posSnakeX[0]++;
	else if (snakeDir == LEFT)
		posSnakeX[0]--;

	// draw
	glColor3f(1.0, 0.7, 0.2);
	for (int i = 0; i < snakeSize; i++)
	{
		glRectd(posSnakeX[i], posSnakeY[i], posSnakeX[i] + 1, posSnakeY[i] + 1);
	}

	// eat
	if (posSnakeX[0] == posFoodX && posSnakeY[0] == posFoodY)
	{
		food = true;

		if (snakeSize != MAX_LEN)
			snakeSize++;
	}

	// hit
	if (posSnakeX == 0 || posSnakeX[0] == gridX - 1 || posSnakeY == 0 || posSnakeY[0] == gridY - 1)
		gameOver = true;

	for (int i = 1; i < snakeSize; i++)
	{
		if (posSnakeX[0] == posSnakeX[i] && posSnakeY[0] == posSnakeY[i])
			gameOver = true;
	}
}

void drawFood()
{
	if (food)
	{
		random(posFoodX, posFoodY);
		food = false;
	}
	glColor3f(0.4, 1.0, 0.6);
	glRectf(posFoodX, posFoodY, posFoodX + 1, posFoodY + 1);
}

void random(int &x, int &y)
{
	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _min = 1;

	srand(time(NULL));

	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY - _min);
}
