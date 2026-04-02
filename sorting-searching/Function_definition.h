//这个头文件用来包含对函数的声明与定义部分
#include<stdio.h>
//冒泡排序的声明与定义部分
void bubble_sorting(int arr[], size_t len_of_arr);

//选择排序的声明与定义部分
void  Selection_Sort(int arr[], size_t len_of_arr);

//打印数组用的函数
void print_arr(int arr[], size_t len_of_arr);

//二分查找大法
int binary_search(int arr[], int len_of_arr,int target);