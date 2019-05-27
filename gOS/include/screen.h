#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

const uint8 SCREEN_WIDTH = 80, SCREEN_HEIGHT = 25, SCREEN_DEPTH = 2;

int CursorX = 0, CursorY = 0;

void ClearLine(uint8 from, uint8 to)
{
	uint16 index = SCREEN_WIDTH * from * SCREEN_DEPTH;

	string vidmem = (string)0xb8000;
	
	for (index; index < (SCREEN_WIDTH * (to + 1) * SCREEN_DEPTH); index++)
	{
		vidmem[index] = 0x0;
	}
}

void UpdateCursor()
{
	unsigned TEMP;
	
	// Position = (Y * WIDTH) + X
	TEMP = CursorY * SCREEN_WIDTH * SCREEN_WIDTH + CursorX;
	
	// CRT Control Register: Select Cursor Location.
	outportb(0x3D4, 14);

	// Send the high byte along the bus
	outportb(0x3D5, TEMP >> 8);

	// CRT Control Register: Select Send Low Byte
	outportb(0x3D4, 15);

	// Send the low byte of the cursor location
	outportb(0x3D5, TEMP);
}

void ClearScreen()
{
	ClearLine(0, SCREEN_HEIGHT - 1);

	CursorX = 0;
	CursorY = 0;

	UpdateCursor();
}

void ScrollUp(uint8 lineNumber)
{
	string vidmem = (string)0xb8000;

	uint16 index = 0;

	for (index; index < SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2; index++)
	{
		vidmem[index + SCREEN_WIDTH * 2 * lineNumber];
	}

	ClearLine(SCREEN_HEIGHT - 1 - lineNumber, SCREEN_HEIGHT - 1);

	if ((CursorY - lineNumber) < 0)
	{
		CursorX = 0;
		CursorY = 0;
	}

	else 
	{
		CursorY -= lineNumber;
	}

	UpdateCursor();
}

void NewLineCheck()
{
	if (CursorY >= SCREEN_HEIGHT - 1) 
	{
		ScrollUp(1);
	}
}

void PrintChar(char C)
{
	string vidmem = (string)0xb8000;

	switch(C)
	{
		// BACKSPACE button
		case (0x08):
			if (CursorX > 0)
			{
				CursorX--;
				vidmem[(CursorY * SCREEN_WIDTH + CursorX) * SCREEN_DEPTH] = 0x00;

			}
			
			break;
		
		// TAB button
		case (0x09):
			CursorX = (CursorX + 8) & ~(8 - 1);
			break;
			
		case ('\r'):
			CursorX = 0;
			break;
			
		case ('\n'):
			CursorX = 0;
			CursorY++;
			break;
			
		default:
			vidmem[((CursorY * SCREEN_WIDTH + CursorX)) * SCREEN_DEPTH] = C;
			vidmem[((CursorY * SCREEN_WIDTH + CursorX)) * SCREEN_DEPTH + 1] = 0x0F;
			CursorX++;
			break;
	}
	
	if (CursorX >= SCREEN_WIDTH) 
	{
		CursorX = 0;
		CursorY++;
	}
	
	NewLineCheck();
	UpdateCursor();
}

void Print(string value)
{
	uint16 index = 0;
	
	for (index; index < StringLength(value); index++)
	{
		PrintChar(value[index]);
	}
}

#endif
