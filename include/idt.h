#ifndef IDT_H
#define IDT_H

#include "types.h"

#define KERNEL_CS 0x08;

typedef struct 
{
	uint8  alwaysZero;
	uint8  flags;
	uint16 lowOffset;
	uint16 highOffset;
	uint16 selection;
} __attribute__((packed)) idtGateT;

typedef struct
{
	uint16 limit;
	uint32 base;
} __attribute__((packed)) idtRegisterT;

#define IDT_ENTRIES 256

idtGateT idt[IDT_ENTRIES];
idtRegisterT idtRegister;

void SetIDT();
void SetIDTGate(int value, uint32 handler);

#endif