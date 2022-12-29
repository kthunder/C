#include <stdio.h>

// 定义函数指针类型, 形如:
// typedef  函数返回值类型  (* 指针变量名) (函数参数列表);
// typedef int (*Fun2)(int, int); // 参数为两个整型，返回值为整型

typedef int (*FuncAType)(int, int);

int callback(FuncAType fp, int arg1, int arg2)
{
	return fp(arg1, arg2);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char const* argv[])
{
	printf("[1, 2]\n");
	printf("max : %d\n", callback(max, 1, 2));
	printf("min : %d\n", callback(min, 1, 2));
	return 0;
}
