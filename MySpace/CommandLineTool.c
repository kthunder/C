#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
	char str[32];
	itoa(0xf, str, 2);
	printf("%s\n", str);
	itoa(0xf0, str, 2);
	printf("%s\n", str);
	itoa(0xf00, str, 2);
	printf("%s\n", str);
	itoa(0xf000, str, 2);
	printf("%s\n", str);
	itoa(0xf0000, str, 2);
	printf("%s\n", str);
	return 0;
}
