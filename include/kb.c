#include "screen.h"
#include "system.h"
#include "types.h"

string ReadString()
{
	char buffer;
	string bufferString;
	
	uint8 index = 0;
	uint8 reading = 1;
	
	while (reading)
	{
		if (inportb(0x64) & (0x1))
		{
			switch (inportb(0x60))
			{
				// ESCAPE
				case 1:
					PrintChar((char)27);
					bufferString[index] = (char)27;
					index++; break;
					
				case 2:
					PrintChar('1');
					bufferString[index] = '1';
					index++; break;
					
				case 3:
					PrintChar('2');
					bufferString[index] = '2';
					index++; break;
					
				case 4:
					PrintChar('3');
					bufferString[index] = '3';
					index++; break;
					
				case 5:
					PrintChar('4');
					bufferString[index] = '4';
					index++; break;
					
				case 6:
					PrintChar('5');
					bufferString[index] = '5';
					index++; break;
					
				case 7:
					PrintChar('6');
					bufferString[index] = '6';
					index++; break;
					
				case 8:
					PrintChar('7');
					bufferString[index] = '7';
					index++; break;
					
				case 9:
					PrintChar('8');
					bufferString[index] = '8';
					index++; break;
					
				case 10:
					PrintChar('9');
					bufferString[index] = '9';
					index++; break;
					
				case 11:
					PrintChar('0');
					bufferString[index] = '0';
					index++; break;
					
				case 12:
					PrintChar('-');
					bufferString[index] = '-';
					index++; break;
					
				case 13:
					PrintChar('=');
					bufferString[index] = '=';
					index++; break;
				
				// BACKSPACE
				case 14:
					PrintChar('\b');
					bufferString[index] = 0;
					index--; 
					
					if (CursorX == 0){
						CursorY--;
						FindLastCharacterOfLine();
						UpdateCursor();
					}

					break;
					
				// TAB
				case 15:
					PrintChar('\t');
					bufferString[index] = '\t';
					index++; break;
					
				case 16:
					PrintChar('q');
					bufferString[index] = 'q';
					index++; break;
					
				case 17:
					PrintChar('w');
					bufferString[index] = 'w';
					index++; break;
				
				case 18:
					PrintChar('e');
					bufferString[index] = 'e';
					index++; break;
					
				case 19:
					PrintChar('r');
					bufferString[index] = 'r';
					index++; break;
					
				case 20:
					PrintChar('t');
					bufferString[index] = 't';
					index++; break;
					
				case 21:
					PrintChar('y');
					bufferString[index] = 'y';
					index++; break;
					
				case 22:
					PrintChar('u');
					bufferString[index] = 'u';
					index++; break;
					
				case 23:
					PrintChar('i');
					bufferString[index] = 'i';
					index++; break;
					
				case 24:
					PrintChar('o');
					bufferString[index] = 'o';
					index++; break;
					
				case 25:
					PrintChar('p');
					bufferString[index] = 'p';
					index++; break;
					
				case 26:
					PrintChar('[');
					bufferString[index] = '[';
					index++; break;
							  
				case 27:
					PrintChar(']');
					bufferString[index] = ']';
					index++; break;
					
				case 28:
					// PrintChar('\n')
					// bufferString = '\n';
					index++; 
					reading = 0; 
					break;
					
				// case 29: LEFT CONTROL
				
				case 30:
					PrintChar('a');
					bufferString[index] = 'a';
					index++; break;
					
				case 31:
					PrintChar('s');
					bufferString[index] = 's';
					index++; break;
					
				case 32:
					PrintChar('d');
					bufferString[index] = 'd';
					index++; break;
					
				case 33:
					PrintChar('f');
					bufferString[index] = 'f';
					index++; break;
					
				case 34:
					PrintChar('g');
					bufferString[index] = 'g';
					index++; break;
					
				case 35:
					PrintChar('h');
					bufferString[index] = 'h';
					index++; break;
					
				case 36:
					PrintChar('j');
					bufferString[index] = 'j';
					index++; break;
					
				case 37:
					PrintChar('k');
					bufferString[index] = 'k';
					index++; break;
					
				case 38:
					PrintChar('l');
					bufferString[index] = 'l';
					index++; break;
					
				case 39:
					PrintChar(';');
					bufferString[index] = ';';
					index++; break;
					
				case 40:
					PrintChar('\'');
					bufferString[index] = '\'';
					index++; break;
					
				case 41:
					PrintChar('`');
					bufferString[index] = '`';
					index++; break;
					
				// LEFT SHIFT
				case 42:
					PrintChar('^');
					bufferString[index] = '^';
					index++; break;
					
				case 43:
					PrintChar('#');
					bufferString[index] = '#';
					index++; break;
					
				case 44:
					PrintChar('z');
					bufferString[index] = 'z';
					index++; break;
					
				case 45:
					PrintChar('x');
					bufferString[index] = 'x';
					index++; break;
					
				case 46:
					PrintChar('c');
					bufferString[index] = 'c';
					index++; break;
					
				case 47:
					PrintChar('v');
					bufferString[index] = 'v';
					index++; break;
					
				case 48:
					PrintChar('b');
					bufferString[index] = 'b';
					index++; break;
					
				case 49:
					PrintChar('n');
					bufferString[index] = 'n';
					index++; break;
					
				case 50:
					PrintChar('m');
					bufferString[index] = 'm';
					index++; break;
					
				case 51:
					PrintChar(',');
					bufferString[index] = ',';
					index++; break;
					
				case 52:
					PrintChar('.');
					bufferString[index] = '.';
					index++; break;
					
				case 53:
					PrintChar('/');
					bufferString[index] = '/';
					index++; break;
					
				// RIGHT SHIFT
				case 54:
					PrintChar('^');
					bufferString[index] = '^';
					index++; break;
					
				// case 56: ALT
				
				case 57:
					PrintChar(' ');
					bufferString[index] = ' ';
					index++; break;
					
				// Home
				case 71:
					CursorX = 0;
					UpdateCursor();
					break;
				
				// End
				case 79:
					FindLastCharacterOfLine();
					UpdateCursor();
					break;
					
				// Page Down
				case 81:
					ScrollUp(1);
			}
		}
	}
	
	bufferString[index] = 0;
	return bufferString;
}