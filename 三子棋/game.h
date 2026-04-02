//函数代码声明部分
#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game();
void Initchessboard(char chessboard[ROW][COL], int row, int col);
void Displaychessboard(char chessboard[ROW][COL], int row, int col);//函数声明，先声明，后使用！
void playerboard(char chessboard[ROW][COL],int row,int col);
void Computerboard(char chessboard[ROW][COL],int row,int col);
char determine_winner_or_loser(char chessboard[ROW][COL], int row, int col);
int  is_draw(char chessboard[ROW][COL], int row, int col);