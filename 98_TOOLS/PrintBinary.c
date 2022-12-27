#include <stdio.h>
#include <stdint.h>

#define MASK 0x80

void printByteBinary(uint8_t* addr)
{
	for (size_t i = 0; i < 8; i++)
		putchar(*addr & (MASK >> i) ? '1' : '0');
}

void printBinary(uint8_t* addr, int32_t nByte)
{
	while (nByte--)
	{
		printByteBinary(addr++);
		putchar(nByte ? ' ' : '\n');
	}
}

int main(int argc, char const* argv[])
{
	uint32_t i = 0xFF00FF00;

	printBinary((uint8_t*)&i, sizeof(uint32_t));

	return 0;
}
