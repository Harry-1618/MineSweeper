#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menue()
{
	printf("***************************************\n");
	printf("**********       1.PLAY        ********\n");
	printf("**********       0.EXIT        ********\n");
	printf("***************************************\n");
}


void game()
{
	char mine[ROWS][COLS]={0};
	char show[ROWS][COLS]={0};

	InitBoard(mine,ROWS,COLS,' ');
	InitBoard(show,ROWS,COLS,'*');

	

	
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	FindMine(mine,show,ROW,COL);
	printf("\n");
	printf("\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menue();
		printf("«Î—°‘Ò£∫");
		scanf("%d", &input);
		while (getchar() != '\n')
			continue;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			break;
		}

	} while (input);


	return 0;
}