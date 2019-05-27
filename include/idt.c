#include "idt.h"
#include "util.h"

void SetIDTGate(int value, uint32 handler)
{
	idt[value].lowOffset = 	
}