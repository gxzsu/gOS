#ifndef UTIL_H
#define UTIL_H

#include "types.h"

extern void MemoryCopy(char *source, char *destination, int nBytes);

extern void MemorySet(uint8 *dest, uint8 value, uint32 len);

extern void IntToASCII(int number, char pString[]);

#endif