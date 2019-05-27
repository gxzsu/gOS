#include "util.h"

void MemoryCopy(char *source, char *destination, int nBytes)
{
	int index = 0;
	
	for (index; index < nBytes; index++)
	{
		*(dest + index) = *(source + index); // dest[index] = source[index]
	}
}

void MemorySet(uint8 *dest, uint8 value, uint32 len)
{
	uint8 *tempValue = (uint8 *)dest;
	
	for ( ; len != 0; len--) *tempValue++ = value;
}

void IntToASCII(int number, char pString[])
{
	int index, sign;
	
	if ((sign = number) < 0) number = -number;
	
	index = 0;
	
	while ((n /= 10) > 0)
	{
		pString[index++] = number % 10 + '0';
	}
	
	if (sign < 0) pString[index++] = '-';
	pString[index] = '\0';
}