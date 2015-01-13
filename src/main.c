#ifndef INC_MAIN
#define INC_MAIN
#include "headers/main.h"
#endif

/*
#include <stdlib.h>
#include <stdio.h>
#include "headers/cpu.h"
#include "instructions.h"

//put it in CONST
#define BLOCK_SIZE sizeof(char) //take the realsize of a char variable
*/
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

	//for eatch iteration, we read the memory of the program, load variables and send it to the function designated by the op_code
	// this should be tested => opcode = (short)((cpu0.memory + ip  << 8) + cpu0.memory + ip + 1);
	
	//switch loop on the op_code, call the function and send arguments (addr, nibble, ect depending of the function, no global variables on that), the cpu is global so shouldn't be sent
	//the op_code in documentation is "All instructions are 2 bytes long and are stored most-significant-byte first. In memory, the first byte of each instruction should be located at an even addresses. If a program includes sprite data, it should be padded so any instructions following it will be properly situated in RAM."
	switch(op_code)
	{
		case 0x0000:
		{
			switch(addr)
			{
				case 0xE0:
					instruc_1();
				break;
				case 0xEE:
					instruc_2();
				break;
			}
		break;

		case (short)0x1000:
		break;
		case 0x2000:
		break;
		case 0x3000:
		break;
		case 0x4000:
		break;
		case 0x5000:
		break;
		case 0x6000:
		break;
		case 0x7000:
		break;
		case 0x8000:
		break;
		case 0x9000:
		break;
		case 0xA000:
		break;
		case 0xB000:
		break;
		case 0xC000:
		break;
		case 0xD000:
		break;
		case 0xE000:
		break;
		case 0xF000:
		break;
		default:
		break;
		}
	}	
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
		fclose(ptr_file);
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
