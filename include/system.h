#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

extern uint8 inportb (uint16 port);

extern void outportb (uint16 port, uint8 data);

#endif
