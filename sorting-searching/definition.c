#include"Function_definition.h"
void bubble_sorting(int arr[], size_t len_of_arr)
{
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
void  Selection_Sort(int arr[], size_t len_of_arr)
{
	printf("OK\n");
}
void print_arr(int arr[], size_t len_of_arr)
{
	int i = 0;
	for (i = 0; i < len_of_arr; i++)
	{
		printf("%d \t", arr[i]);
	}
}