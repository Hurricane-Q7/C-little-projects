#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//定义一个结构体，存放当前时间
typedef struct CurrentTime
{
	int curYear;
	int curMonth;
	int curDay;
}CurrentTime;

//判断一年是不是闰年，是闰年就返回1，不是闰年就返回0
int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}
//计算某天是今年第几天的函数
int getDayOfYear(int year, int month, int day)
{
	int sum_Of_Day = 0;
	int day_of_every_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//在求和统计之前先判断是不是闰年
	if (isLeapYear(year))
	{
		day_of_every_month[2] = 29;
	}
	//把从正月到上一月的天数全部加起来
	int i = 0;
	for (i = 1; i < month; i++)
	{
		sum_Of_Day += day_of_every_month[i];
	}
	//最后把本月的已过的天数也加起来
	sum_Of_Day += day;
	return sum_Of_Day;
}
//主函数入口
int main()
{
	CurrentTime CurTime;
	//1. 获取系统时间
	time_t nowTimeStamp = time(NULL);
	struct tm* ptm = localtime(&nowTimeStamp);

	//增加检功能，提升代码的健壮性
	if (ptm == NULL)
	{
		printf("警告！获取系统时间出现错误！程序已经退出！\n");
		return 1;
	}
	//将获取到的时间放到结构体变量CurTime的成员里面
	CurTime.curYear = ptm->tm_year + 1900;
	/*CurTime.curMonth = ptm->tm_mon + 1;
	CurTime.curDay = ptm->tm_mday;*/
	CurTime.curMonth = 12;
	CurTime.curDay = 12;
	//2. 设置目标时间
	int targetYear = CurTime.curYear;
	const int targetMonth = 12;
	const int targetDay = 12;//加const防止被修改
	//3. 计算今天和12月12日分别是今年的第几天
	int currentDayOfYear = getDayOfYear(CurTime.curYear,CurTime.curMonth,CurTime.curDay);
	int targetDayOfYear = getDayOfYear(CurTime.curYear, targetMonth, targetDay);
	int remainDayOfExam = 0;//真正要输出的变量，距离4级考试还有多少天。
	if (currentDayOfYear<targetDayOfYear)
	{
		//第一种情况，直接相减就好了
		remainDayOfExam = targetDayOfYear - currentDayOfYear;
	}
	else if(currentDayOfYear>targetDayOfYear)
	{
		// 今年的考试日期已经过去，计算到下一年的考试日期
		targetYear = CurTime.curYear + 1;//更新目标年份
		int nextYear = CurTime.curYear + 1;
		//计算今年总共有多少天，无非就是366和365，所以判断是不是闰年即可
		int thisYearTotalDay = isLeapYear(CurTime.curYear) ? 366 : 365;
		//计算下一年的12月12日是下一年的第几天
		int nextYearTargetDayOfYear = getDayOfYear(nextYear,targetMonth,targetDay);
		//重新计算现在到下一年12月12日,今年剩下的天数+ 下一年第一天到目标天数的总天数。
		remainDayOfExam = (thisYearTotalDay - currentDayOfYear) + nextYearTargetDayOfYear;
	}
	else
	{
		printf("今天就要考Cet-4了，你准备好了吗？\n");
		return 0;
	}
	//打印输出结果
	printf("==================== Cet-4 倒计时程序 ====================\n");
	printf("你当前时间是：%d年-%d月-%d日！\n",CurTime.curYear,CurTime.curMonth,CurTime.curDay );
	printf("目标考试时间：%d年-%d月-%d日！\n",targetYear,targetMonth,targetDay);
	printf("距离%d年的Cet-4考试你还有%d天的时间，好好复习！\n", targetYear, remainDayOfExam);
	printf("==================== Cet-4 倒计时程序 ====================\n");
	system("pause");
	return 0;
}