#include "string.h"

extern uint16 StringLength(string passedString)
{
	uint16 i = 1;
	while(passedString[i++]);
	return --i;
}

extern char StringLengthPrintable(string passedString)
{
	uint16 i = 1;
	while (passedString[i++]);
	i = --i;
	i = i + 48;
	
	char c = i;
	
	return c;
}

extern uint8 StringEqual(string pString1, string pString2)
{
	uint8 result = 1;
	
	uint8 size = StringLength(pString1);
	
	if (size != StringLength(pString2)) result = 0;
	
	else
	{
		uint8 index = 0;
		
		for (index; index <= size; index++)
		{
			if (pString1[index] != pString2[index]) result = 0;
		}
	}
	
	return result;
}