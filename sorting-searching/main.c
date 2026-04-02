#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Function_definition.h"
//rand生成的范围是0~rand_max(32767)
//利用rand随机生成指定范围数字的步骤（a~b）1 ~ 100
//1. 1-101
//2. 1-100
//3. rand()%100+1
int main()
{
	srand((unsigned int)time(NULL));
	int arr[1000] = { 0 };
	char input = 0;
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		arr[i] = rand()%1000+1;//生成1~1000数字
	}
	size_t len_of_arr = sizeof(arr) / sizeof(arr[0]);
	printf("我已经生成好了1~1000内的数字,接下来选择排序算法模型：\n");
	printf("a. 冒泡排序\nb. 选择排序 \nc.developing……\n");
	printf("请输入每种排序算法(升序)前的字母来做选择:>");
	scanf("%c",&input);
	switch (input)
	{
	case 'a':
		bubble_sorting(arr, len_of_arr);
		break;
	case 'b':
		Selection_Sort(arr,len_of_arr);
		break;
	case 'c':
		printf("正在开发中……\n");
		break;
	default :
		printf("输入错误，请重新输入!\n");
	}
	printf("已经为你排好序了：\n");
	print_arr(arr, len_of_arr);
	return 0;
}