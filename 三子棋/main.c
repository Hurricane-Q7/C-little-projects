//test.c是用来表示游戏主逻辑的,一些函数的功能另在别处
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"//包含该头文件，用来对函数进行声明
void menu()//菜单提示信息
{
	printf("*************************\n");
	printf("****1.play 0.exit********\n");
	printf("*************************\n");
}
void game()
{
	char return_value = 0;
	char chessboard[ROW][COL] = { 0 };
	Initchessboard(chessboard, ROW, COL);//对数组进行初始化，将每个数组元素初始化为空格
	printf("已生成棋盘，开始玩吧！\n");
	Displaychessboard(chessboard, ROW, COL);//打印键盘部分
	while (1)
	{
		playerboard(chessboard, ROW, COL);
		//判断输赢
		return_value = determine_winner_or_loser(chessboard, ROW, COL);
		if (return_value != 'C')
		{
			break;
		}
		Displaychessboard(chessboard, ROW, COL);
		Computerboard(chessboard, ROW, COL);
		//判断输赢
		return_value = determine_winner_or_loser(chessboard, ROW, COL);
		if (return_value != 'C')
		{
			break;
		}
		Displaychessboard(chessboard, ROW, COL);
	}
	if (return_value == '*')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (return_value == '#')
	{
		printf("你输了，竟然下不过！\n");
	}
	else if (return_value == 'Q')
	{
		printf("平局，不分上下！\n");
	}
	Displaychessboard(chessboard, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{//用do……while可以让程序先执行一次，起码来一局吧
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("成功退出游戏，期待下次相遇！\n");
			break;
			break;
		}
	} while (input);
	return 0;
}


