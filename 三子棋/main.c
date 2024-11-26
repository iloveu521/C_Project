#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	char ret = '0';
	char map[ROW][COL] = { 0 };
	//Initialize the map
	Init_map(map, ROW, COL);
	//Display the map
	Display_map(map, ROW, COL);
	//Player play
	while (1)
	{
		Playermove(map, ROW, COL);
		Display_map(map, ROW, COL);
		//Judge winner
		ret = iswin(map, ROW, COL);
		if (ret == '*')
		{
			printf("Player win!\n");
			break;
		}
		if (ret == '#')
		{
			printf("Computer win!\n");
			break;
		}
		if(ret == 'D')
		{
			printf("This game is a draw!\n");
			break;
		}
		Computermove(map, ROW, COL);
		Display_map(map, ROW, COL);
		ret = iswin(map, ROW, COL);
		if (ret == '*')
		{
			printf("Player win!\n");
			break;
		}
		if (ret == '#')
		{
			printf("Computer win!\n");
			break;
		}
		if(ret == 'D')
		{
			printf("This game is a draw!\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int choice = 0;
	//print the mnenu
	//Enter the option
	do
	{
		mnenu();
		printf("Please enter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit game\n");
			break;
		default:
			printf("Enter Error, please enter again:\n");
			break;
		}
	} while (choice);
	
	return 0;
}