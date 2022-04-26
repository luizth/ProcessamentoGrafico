#pragma once

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX_LEN 60

void initGrid(int, int);
void drawGrid(void);
void drawUnit(int, int);
void drawSnake();
void drawFood();
void random(int&, int&);
