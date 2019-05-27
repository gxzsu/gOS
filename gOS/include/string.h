#ifndef STRING_H
#define STRING_H

#include "types.h"

uint16 StringLength(string passedString)
{
	uint16 i = 1;
	while(passedString[i++]);
	return --i;	
}

#endif
