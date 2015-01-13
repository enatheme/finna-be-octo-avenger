#include <stdlib.h>
#include <stdio.h>

#ifndef INC_CPU
#define INC_CPU
#include "cpu.h"
#endif

#ifndef INC_INSTRUCTIONS
#define INC_INSTRUCTIONS
#include "instructions.h"
#endif

#define BLOCK_SIZE sizeof(char) //take the char variable realsize

void emulate();
void open_rom(char *path);
int main(int argc, char *argv[]);
