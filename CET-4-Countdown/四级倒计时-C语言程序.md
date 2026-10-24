# 四级倒计时-C语言程序

## 项目介绍

**注意:**该项目的默认考试时间是当前年份的12月12日。

该项目是我用`C语言`实现的一个倒计时程序，用于放置桌面上题型自己距离四级考试还有多少天。

## tm时间结构体

``` c
struct tm {
    int tm_sec;   // 秒 [0, 60]  60是闰秒
    int tm_min;   // 分 [0, 59]
    int tm_hour;  // 时 [0, 23]
    int tm_mday;  // 日 [1, 31]
    int tm_mon;   // 月 [0, 11]  ⚠️重点：0代表1月！
    int tm_year;  // 年：减去1900   ⚠️重点：2026年存 126
    int tm_wday;  // 星期 [0,6]  0=周日，1=周一...6=周六
    int tm_yday;  // 一年中的第几天 [0,365]  0=1月1日
    int tm_isdst; // 夏令时标记：正数=夏令时，0=不是，负数未知
};
```



## localtime函数

头文件：<time.h>

**原型：**`struct tm * localtime(const time_t * timer);`

**作用： **把 time_t 时间戳 → 本地时区的 struct tm.

**参数：**

1. timer:指向`time_t` 变量的指针，time_t 是秒时间戳

``` c
//用法介绍
time_t now = time(NULL);
struct tm *p = localtime(&now);
```

**返回值**

返回一个struct tm 指针 

⚠️ 重点大坑：这个指针指向**函数内部静态缓冲区**，不是你自己开辟的内存！

 ✅ 意味着：**每次调用 localtime，会覆盖上一次的内容！**

``` c
//错误示例
time_t t1 = 1760000000;
time_t t2 = 1760000600;
struct tm *p1 = localtime(&t1);
struct tm *p2 = localtime(&t2);
// p1 和 p2 是同一个地址！p1的值已经被p2覆盖

//正确做法
//C语言的结构体拷贝语法
struct tm tm1 = *localtime(&t1);
struct tm tm2 = *localtime(&t2);


```



## 项目感悟

1. 自己再写一个功能的时候，要考虑要加一些检查的功能，比如传给函数的值，合不合法，加个if语句排查一下，再比如申请一块内存空间，也要判断一下
2. 这个小项目，涉及到了一些不知道的东西，比如`tm结构体`和`localtime函数`，还有忘掉的C语言知识`结构体拷贝`
