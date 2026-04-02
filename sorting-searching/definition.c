#include"Function_definition.h"
void bubble_sorting(int arr[], int len_of_arr)
{
	printf("冒泡排序比较慢，请耐心等待！\n");
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < len_of_arr - 1; i++)
	{
		//外层循环解决趟的问题
		for (j = 0; j < len_of_arr - 1 - i; j++)
		{
			//内层循环解决趟的问题
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void  Selection_Sort(int arr[], int len_of_arr)
{
	int i = 0;
	int tmp = 0;//tmp变量用来当作一个中间变量用于交换，过渡一下
	int j = 0;
	for (i = 0; i < len_of_arr - 1; i++)
	{
		//外层循环表示len_of_arr排好序一共要进行多少轮
		int p = i;
		//变量p用来记录当前最小的元素下标
		for (j = i+1; j < len_of_arr; j++)
		{
			if (arr[p] > arr[j])
			{
				p = j;
			}
		}
		if (p != i)
		{
			tmp = arr[i];
			arr[i] = arr[p];
			arr[p] = tmp;
		}
	}
}
//二分查找，如果找到的话就返回元素下标，找不到的话就返回-1
 int binary_search(int arr[], int len_of_arr,int target)
{
	 //左闭右闭区间
	 int left_idx = 0;
	 int right_idx = len_of_arr - 1;
	 
	 while (left_idx <= right_idx)
	 {
		 int mid_idx = left_idx + (right_idx - left_idx) / 2;
		 if (arr[mid_idx] > target)
		 {
			 //说明arr[mid_idx]在target的右边，更新右边下标
			 right_idx = mid_idx - 1;
		 }
		 else if (arr[mid_idx] < target)
		 {
			 left_idx = mid_idx + 1;

		 }
		 else
			 return mid_idx;
	 }
	 return -1;//找不到
}
void print_arr(int arr[], int len_of_arr)
{
	int i = 0;
	for (i = 0; i < len_of_arr; i++)
	{
		printf("%d \t", arr[i]);
	}
	printf("\n");
}