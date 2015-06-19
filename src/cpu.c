#ifndef INC_CPU
#define INC_CPU
#include "headers/cpu.h"
#endif

#include <stdlib.h>
#include <stdio.h>

void push_8(char input)
{
	cpu0.memory[cpu0.sp] = input & 0xff;
	inc_sp();
}

void push_12(short input)
{
	cpu0.memory[cpu0.sp] = (8 >> input & 0xf00) & 0x0f;
	inc_sp();
	push_8((char)input & 0x0ff);
}

char pop_8()
{
	dec_sp();
	return(cpu0.memory[cpu0.sp]);
}

void inc_sp()
{
	if((cpu0.sp + 1) < 4095)
	{
		cpu0.sp++;
	}
	else
	{
		//ERROR MESSAGE !
		exit(0);
	}
}

void dec_sp()
{
	if((cpu0.sp - 1) > cpu0.bp)
	{
		cpu0.sp++;
	}
	else
	{
		//ERROR MESSAGE !
		exit(0);
	}
}
