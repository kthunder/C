#include <stdio.h>
#include <stdint.h>

// x86 contex-M3
// 0x00140E03;
// 0000 0000 0001 0100 0000 1110 0000 0011
void printBinary(void* addr, int32_t nByte)
{
	while (nByte--)
	{
		for (size_t i = 0; i < 8; i++)
		{
			putchar(*(uint8_t*)(addr + nByte) & (0x80 >> i) ? '1' : '0');
			if (i == 3) putchar(' ');
		}
		putchar(nByte ? ' ' : '\n');
	}
}

int main(int argc, char const* argv[])
{
	uint32_t i = 0x00140E03;
	// 0000 0000 0001 0100 0000 1110 0000 0011

	printBinary(&i, sizeof(uint32_t));

	return 0;
}
