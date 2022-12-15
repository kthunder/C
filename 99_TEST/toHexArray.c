#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

void clearInput();

char* readHexArray(char* szBuffer);

int main()
{
	char szBuffer[MAXLEN] = {0};
	while (1)
	{
		if (readHexArray(szBuffer))
		{
			char* pBuffer = szBuffer;
			printf("{");
			while (*pBuffer != '\0')
			{

				printf("0x");
				putchar(*pBuffer++);
				putchar(*pBuffer++);
				if (*pBuffer != '\0')
				{
					printf(", ");
				}
			}
			printf("};\n");
		}
	}

	return 0;
}

void clearInput()
{
	while (getchar() != '\n')
		;
}

char* readHexArray(char* szBuffer)
{

	char* pBuffer = szBuffer;
	char ch = 0;
	if (!pBuffer)
	{
		return 0;
	}
	puts("please type in data:");
	while ((ch = getchar()) != '\n')
	{
		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
		{
			*pBuffer++ = ch;
		}
		else
		{
			clearInput();
			printf("'%c' isn't a hexadecimal character\n", ch);
			return 0;
		}

		if (pBuffer - szBuffer >= MAXLEN)
		{
			clearInput();
			puts("Array out of bounds!");
			return 0;
		}
	}
	*pBuffer = '\0';
	if (strlen(szBuffer) % 2 != 0)
	{
		puts("StringLen mast be even number!");
		return 0;
	}
	return szBuffer;
}