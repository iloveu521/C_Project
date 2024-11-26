#pragma once
#ifndef __GAME_H
#define __GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void mnenu(void);
void Playermove(char map[ROW][COL], int row, int col);
int Computermove(char map[ROW][COL], int row, int col);
char iswin(char map[ROW][COL], int row, int col);



#endif // !__GAME_H
