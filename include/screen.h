#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

extern const uint8 SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH;

extern int CursorX, CursorY;

extern void ClearLine(uint8 from, uint8 to);

extern void UpdateCursor();

extern void FindLastCharacterOfLine();

extern void ClearScreen();

extern void ScrollUp(uint8 lineNumber);

extern void NewLineCheck();

extern void PrintChar(char C);

extern void Print(string value);

#endif
