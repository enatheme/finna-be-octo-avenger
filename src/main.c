
#include <stdlib.h>
#include <stdio.h>
#include "headers/cpu.h"

//put it in CONST
#define BLOCK_SIZE sizeof(char) //take the realsize of a char variable

Cpu cpu0;

void emulate()
{
	//variables
	short op_code = 0;
	short addr = 0; //should be 12 bits name in the doc : nnn or addr
	char nibble = 0; //should be 4 bits name in the doc : n or nibble
	char x = 0; //should be 4 bits name in the doc : x
	char y = 0; //should be 4 bits name in the doc : y
	char byte = 0; //name in the doc : kk or byte

	//at eatch iteration, we read the memory of the program, load variables and send it to the function designated by the op_code
	opcode = (short)((cpu0.memory + ip  << 8) + cpu0.memory + ip + 1);
	
}

void open_rom(char *path)
{

	//now we read the rom
	FILE *ptr_file;
	unsigned long i = 0x200; //counter to read the rom
	unsigned long file_len = 0; //size of the rom
	ptr_file = fopen(path, "r");
	if(ptr_file != NULL)
	{
		//get the size of the rom
		fseek(ptr_file, 0, SEEK_END);
		file_len = ftell(ptr_file);
		fseek(ptr_file, 0, SEEK_SET);

		//read the rom
		fread(cpu0.memory + i, file_len, 1, ptr_file);
		while(i < file_len + 0x200)
		{
			printf("%.2X", cpu0.memory[i]);
			i+= sizeof(char);
			if (i % 4 == 3)
			{
				printf(" ");
			}

			// Display 16 bytes per line
			if (i % 16 == 15)
			{
				printf("\n");
			}
		}
		close(ptr_file);
	}
	else
	{
		//error on the opening of the rom file
		fprintf(stderr, "ERROR ON THE OPENING !\n");
		exit(-1);
	}
}


//main function, contain the cpu variables and run all the things
//argv[1] = filepath to the rom
int main(int argc, char *argv[])
{
	cpu0.ip = 0x200;
	open_rom(argv[1]);
}
