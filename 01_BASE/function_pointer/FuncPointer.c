#include <stdio.h>

// 形如
// typedef  函数返回值类型  (* 指针变量名) (函数参数列表);

// typedef int (*Fun1)(int);	   // 声明也可写成int (*Fun1)(int x)，但习惯上一般不这样。
// typedef int (*Fun2)(int, int); // 参数为两个整型，返回值为整型
// typedef void (*Fun3)(void);	   // 无参数和返回值
// typedef void* (*Fun4)(void*);  // 参数和返回值都为void*指针

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const* argv[])
{
	int (*funcPointer)(int, int); // 定义一个函数指针
	int a = 1;
	int b = 2;
	int c = 0;

	funcPointer = max; // 把函数Max赋给指针变量p, 使p指向Max函数

	c = (*funcPointer)(a, b);

	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("c = %d\n", c);
    printf("max == &max\n");
	printf("max = %p\n", max);
	printf("&max = %p\n", &max);
	/* code */
	return 0;
}
