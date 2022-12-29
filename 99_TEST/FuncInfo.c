#include <stdio.h>

int main(int argc, char const* argv[])
{
	printf("[%s %s] %s: %s: %d\n", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__);
	return 0;
}