//这个源文件中主要用来包含函数的定义部分，详细写了函数具体的功能与怎么实现的！
#include"game.h"
void Initchessboard(char chessboard[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';//其实还是对数组元素的替换
		}
	}
}

//
//
//first version
//void Displaychessboard(char chessboard[ROW][COL], int row, int col)//输出棋盘函数
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", chessboard[i][0], chessboard[i][1], chessboard[i][2]);
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//}
//棋盘：
// a | a | a 
//---|---|---
// a | a | a
//---|---|---
// a | a | a
//说一下这里的实现逻辑：
//这里把棋盘抽象成了又两个部分组成的整体
// 部分一之棋子信息：a | a | a
// 部分二之分隔信息：---|---|---
//这里把这两个部分分别认为是一行的内容，所以在第一版中只用row来限制就行了，但是第一版的输出格式有点死板，
//因为那样的列数是死的，固定只有3列
void Displaychessboard(char chessboard[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//外层for循环控制一共要输出几行，也就是row行！
	{
		//打印棋子信息
		int j = 0;
		for (j = 0; j < row; j++)//这个for循环表示每一行具体怎么输出，输出 a | a | a 
		{
			printf(" %c ", chessboard[i][j]);
			if (j < col - 1)
			{                   
				printf("|");
			}
		}
		printf("\n");
		//打印分隔信息
		//---|---|---
		if(i<row-1)
		{ 
		for (j = 0; j < row; j++)
		{
			printf("---");
			if (j < col - 1)
			{
				printf("|");
			}
		}
		}
		printf("\n");
	}
}
//玩家下棋,通过输入坐标的方式来实现下棋，本质上是对chessboard数组元素的一个替换
// a | a | a  
//---|---|---
// a | a | a
//---|---|---
// a | a | a
// 这里的实际坐标是数组元素的下标，0，1，2
//
// 玩家可不懂数组，应该转换一下，面向用户设计
//  1 2 3
//1
//2
//3
void playerboard(char chessboard[ROW][COL],int row,int col)
{
	//玩家输入部分
	//1. 接收坐标
	//2. 检验坐标是否合法
	//3. 替换元素

	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请玩家输入坐标(纵坐标：1 2 3，横坐标：1 2 3):");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= 3) && (y >= 1 && y <= 3))
		{
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '*';
				break;
			}
			else 
				if ((chessboard[x - 1][y - 1] == '*')||(chessboard[x-1][y-1])=='#')
				{
					printf("此位置已经有棋子了，重新输入坐标！\n");
				}
		}
		else
		{
			printf("输入非法，请重新输入！\n");
		}
	}
}
void Computerboard(char chessboard[ROW][COL], int row, int col)
{
	//实现电脑下棋功能，采用随机数的生成方式
	//要求：
	//1. 电脑下棋的棋子样式不能与玩家的一样
	//2. 电脑下棋的地方必须是空白的棋子位置，不能有别的棋子比如玩家的‘*’
	int x = 0;
	int y = 0;
	printf("电脑棋手V1.0下棋：\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;//生成0~2的数字
		if (chessboard[x][y] == ' ')
		{
			chessboard[x][y] = '#';
			break;
		}
		
	}
}
int is_draw(char chessboard[ROW][COL], int row, int col)//用来检验是否平局的情况，算法思想：遍历数组看有无空字符，有空字符表示非平局情况返回1，无则平局（棋子下满，未分出胜负），返回0
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (chessboard[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}
//判断输赢：
// 1. 三行元素都相同
// 2. 三列元素都相同
// 3. 两条对角线上得元素都相同
// 约定：
// 1. 返回*，玩家Victory
// 2. 返回#, 电脑Victory
// 3. 返回Q，平局，不分上下
// 4. 返回C，游戏还没有结束
char determine_winner_or_loser(char chessboard[ROW][COL], int row, int col)
{
	//先判断行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][0] == chessboard[i][2] && chessboard[i][0] != ' ')
		{
			return chessboard[i][0];
		}
	}
	//再判断列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (chessboard[0][j] == chessboard[1][j] && chessboard[0][j] == chessboard[2][j] && chessboard[0][j] != ' ')
		{
			return chessboard[0][j];
		}
	}
	//再判断对角线上
	if (chessboard[0][0] == chessboard[1][1] && chessboard[0][0]==chessboard[2][2] && chessboard[0][0] != ' ')
	{
		return chessboard[0][0];
	}
	if (chessboard[0][2] == chessboard[1][1] && chessboard[0][2]==chessboard[2][0] && chessboard[0][2] != ' ')
	{
		return chessboard[0][2];
	}
	if (!is_draw(chessboard, row, col))
	{
		return 'Q';
	}
	return 'C';
}















