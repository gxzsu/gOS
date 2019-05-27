#include "include/kb.h"

int kmain()
{
	ClearScreen();
	
	Print("gOS [Version 0.0.0]\n");
	Print("Copyright (c) 2018 Gareth Egglestone. All rights reserved.\n");
	Print("    - Not to be distributed.\n\n");
	
	while(1)
	{
		Print(">> ");
		
		string keyPressed = ReadString();
		
		Print("\n");
	}
}
