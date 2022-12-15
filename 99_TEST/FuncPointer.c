#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char const* argv[])
{
	int (*pFunc)(int, int) = &max;

	printf("%d\n", pFunc(99, 54));
	return 0;
}
