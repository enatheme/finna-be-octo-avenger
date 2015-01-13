#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

#define BLOCK_SIZE sizeof(char) //take the char variable realsize

void emulate();
void open_rom(char *path);
int main(int argc, char *argv[]);
