#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)  //初始化雷区
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}



void DisplayBoard(char board[ROWS][COLS], int row, int col)  //显示雷区
{
	int i = 0;
	int j = 0;

	printf("-----------扫雷游戏--------------\n");
	for(i=0;i<=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------扫雷游戏--------------\n");

}

void SetMine(char mine[ROWS][COLS], int row, int col)  //设置雷区
{
	int count = EasyCount;

	while (count > 0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == ' ')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //搜寻周围八个格子的地雷个数
{
	if (row >= 1 && row <= 9 && col >= 1 && col <= 9)
	{
		int i = 0;
		int j = 0;
		int num = 0;
		for (i = -1; i < 2; i++)
			for (j = -1; j < 2; j++)
			{
				if (mine[row + i][col + j] == ' ')
				{
					num++;
				}
			}
		if (num < 9)
		{
			return 9-num;
		}
		else
		{
			return 0;
		}
	}

	return 0;
}

void ExpandBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win)  //向外扩展
{
	int count = find_mine(mine, show, x, y);
	(*win)++;
	if (count == 0)
	{
		int i = 0;
		int j = 0;
		show[x][y] = ' ';
	/*	
		if (show[x - 1][y - 1] == '*' && x - 1 > 0 && x - 1 < ROWS && y - 1 > 0 && y - 1 < COLS && mine[x-1][y-1]==' ')
			ExpandBoard(mine, show, x - 1, y - 1, win);
		if (show[x - 1][y] == '*' && x - 1 > 0 && x - 1 < ROWS && y > 0 && y < COLS && mine[x - 1][y] == ' ')
			ExpandBoard(mine, show, x - 1, y, win);
		if (show[x - 1][y + 1] == '*' && x - 1 > 0 && x - 1 < ROWS && y + 1 > 0 && y + 1 < COLS && mine[x-1][y+1]==' ')
			ExpandBoard(mine, show, x - 1, y + 1, win);
		if (show[x][y - 1] == '*' && x > 0 && x < ROWS && y - 1 > 0 && y - 1 < COLS && mine[x][y-1]==' ')
			ExpandBoard(mine, show, x, y - 1, win);
		if (show[x][y + 1] == '*' && x > 0 && x < ROWS && y + 1 > 0 && y + 1 < COLS && mine[x][y+1]==' ')
			ExpandBoard(mine, show, x, y + 1, win);
		if (show[x + 1][y - 1] == '*' && x + 1 > 0 && x + 1 < ROWS && y - 1 > 0 && y - 1 < COLS && mine[x+1][y-1]==' ')
			ExpandBoard(mine, show, x + 1, y - 1, win);
		if (show[x + 1][y] == '*' && x + 1 > 0 && x + 1 < ROWS && y > 0 && y < COLS && mine[x+1][y]==' ')
			ExpandBoard(mine, show, x + 1, y, win);
		if (show[x + 1][y + 1] == '*' && x + 1 > 0 && x + 1 < ROWS && y + 1 > 0 && y + 1 < COLS && mine[x+1][y+1]==' ')
			ExpandBoard(mine, show, x + 1, y + 1, win);*/
		for(i=-1;i<2;i++)
			for (j = -1; j < 2; j++)
			{
				if (show[x + i][y + j] == '*' && x + i > 0 && x + i <= ROW && y + j  > 0 && y + j <= COL && mine[x + i][y + j] == ' ')
					ExpandBoard(mine, show, x + i, y + j, win);
			}
	}
	else
	{

		show[x][y] = count + '0';
	}


	
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)  //游戏开始总操控
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (1)
	{
		
		printf("请输入你所选的坐标：(如：2【空格】3，表示第二行第三列)");
		scanf("%d %d", &x, &y);
		while (getchar() != '\n')
			continue;

		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]!=' ')
		{
			if (mine[x][y] == '1')
			{
				printf("你已被炸死\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				ExpandBoard(mine, show, x, y, &win);
				DisplayBoard(show, ROW, COL);
				if ((ROW) * (COL) - win == EasyCount)
				{
					goto end;
				}
			}
		}
		else
		{
			printf("非法输入！！！\n");
		}
		
	}

end:if ((ROW) * (COL)-win == EasyCount)
	{
		printf("你赢了！！\n");
		DisplayBoard(mine, ROW, COL);

	}

}
