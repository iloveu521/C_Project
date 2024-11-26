#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void mnenu(void)
{
	printf("*******************************************\n");
	printf("************Input 1:Start game*************\n");
	printf("************Input 0:Exit  game*************\n");
	printf("*******************************************\n");
}

void Init_map(char map[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void Display_map(char map[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", map[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			printf("---|---|---\n");
		}
	}
}

void Playermove(char map[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Player`s turn:\n");
	while (1)
	{
		printf("Please enter the coordinates of the chess pieces(x->空格->y->回车):");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (map[x - 1][y - 1] == ' ')
			{
				map[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("The coordinates are occupied, please re-enter\n");
			}
		}
		else
		{
			printf("The coordinates are out of boundaries, please re-enter\n");
		}
	}
}

int Computermove(char map[ROW][COL], int row, int col)
{
	printf("Computer`s turn:\n");
	int x = 0;
	int y = 0;
	// 定义方向向量，上下左右
	int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	//diagonal line
	if (map[0][0] == map[1][1] && map[2][2] == ' ' && map[0][0] != ' ')
	{
		map[2][2] = '#';
		return 1;
	}
	if (map[0][0] == map[2][2] && map[1][1] == ' ' && map[0][0] != ' ')
	{
		map[1][1] = '#';
		return 1;
	}
	if (map[1][1] == map[2][2] && map[0][0] == ' ' && map[1][1] != ' ')
	{
		map[0][0] = '#';
		return 1;
	}

	if (map[0][2] == map[1][1] && map[2][0] == ' ' && map[0][2] != ' ')
	{
		map[2][0] = '#';
		return 1;
	}
	if (map[0][2] == map[2][0] && map[1][1] == ' ' && map[0][2] != ' ')
	{
		map[1][1] = '#';
		return 1;
	}
	if (map[1][1] == map[2][0] && map[0][2] == ' ' && map[1][1] != ' ')
	{
		map[0][2] = '#';
		return 1;
	}
	//Screening for special cases
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//rows
			if (j == 0)
			{
				for (int z = 0; z < 3; z++)
				{
					if (i + z < row)
					{
						if (map[i + z][j] == map[i + z][j + 2] && map[i + z][j + 1] == ' ')
						{
							map[i + z][j + 1] = '#';
							return 1;
						}
						if (map[i + z][j] == map[i + z][j + 1] && map[i + z][j + 2] == ' ')
						{
							map[i + z][j + 2] = '#';
							return 1;
						}
					}
					if (i + z == row)
					{
						if (map[0][j] == map[0][j + 2] && map[0][j + 1] == ' ')
						{
							map[0][j + 1] = '#';
							return 1;
						}
						if (map[0][j] == map[0][j + 1] && map[0][j + 2] == ' ')
						{
							map[0][j + 2] = '#';
							return 1;
						}
					}
					if (i + z == row + 1)
					{
						if (map[1][j] == map[1][j + 2] && map[1][j + 1] == ' ')
						{
							map[1][j + 1] = '#';
							return 1;
						}
						if (map[1][j] == map[1][j + 1] && map[1][j + 2] == ' ')
						{
							map[1][j + 2] = '#';
							return 1;
						}
					}
				}
			}
			//columns
			if (i == 0)
			{
				for (int z = 0; z < 3; z++)
				{
					if (j + z < row)
					{
						if (map[i][j + z] == map[i + 2][j + z] && map[i + 1][j + z] == ' ')
						{
							map[i + 1][j + z] = '#';
							return 1;
						}
						if (map[i][j + z] == map[i + 1][j + z] && map[i + 2][j + z] == ' ')
						{
							map[i + 2][j + z] = '#';
							return 1;
						}
					}
					if (i + z == row)
					{
						if (map[i][0] == map[i + 2][0] && map[i + 1][0] == ' ')
						{
							map[i + 1][0] = '#';
							return 1;
						}
						if (map[i][0] == map[i + 1][0] && map[i + 2][0] == ' ')
						{
							map[i + 2][0] = '#';
							return 1;
						}
					}
					if (i + z == row + 1)
					{
						if (map[i][1] == map[i + 2][1] && map[i + 1][1] == ' ')
						{
							map[i + 1][1] = '#';
							return 1;
						}
						if (map[i][1] == map[i + 1][1] && map[i + 2][1] == ' ')
						{
							map[i + 2][1] = '#';
							return 1;
						}
					}
				}
			}
		}
	}
	//Find a space nearing to the '*'
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// 如果当前位置是 '*'
			if (map[i][j] == '*')
			{
				// 遍历四个方向
				for (int d = 0; d < 4; d++)
				{
					int new_x = i + directions[d][0];
					int new_y = j + directions[d][1];

					// 检查是否在边界内且为空
					if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && map[new_x][new_y] == ' ')
					{
						map[new_x][new_y] = '#';
						return 1;
					}
				}
			}
		}
	}
	return 0;

}
int isfull(char map[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (map[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char map[ROW][COL], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && map[i][1] != ' ')
		{
			return map[i][1];
		}
	}
	//列
	for (int i = 0; i < row; i++)
	{
		if (map[0][i] == map[1][i] && map[1][i] == map[2][i] && map[1][i] != ' ')
		{
			return map[1][i];
		}
	}
	//对角线
	int i = 0;
	if (map[i][i] == map[i + 1][i + 1] && map[i + 1][i + 1] == map[i + 2][i + 2] && map[i + 1][i + 1] != ' ')
	{
		return map[i + 1][i + 1];
	}
	int j = 2;
	if (map[j][j] == map[j - 1][j - 1] && map[j - 1][j - 1] == map[j - 2][j - 2] && map[j - 1][j - 1] != ' ')
	{
		return map[i + 1][i + 1];
	}
	if (isfull(map, row, col))
	{
		return 'D';
	}
}