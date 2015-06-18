#ifndef INC_MAIN
#define INC_MAIN
#include "headers/main.h"
#endif

#define DEBUG

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
	char dbyte1 = 0;
	char dbyte2 = 0;
	
	/*
	 * addr should be 12 bits name in the doc : nnn or addr
	 * nibble should be 4 bits name in the doc : n or nibble
	 * x should be 4 bits name in the doc : x
	 * y should be 4 bits name in the doc : y
	 * byte name in the doc : kk or byte
	 * 
	 *  ___________________
	 * |0xf0|0x0f|0xf0|0x0f|
	 * |____|____|____|____|
	 * |dbyte1   | dbyte2  |
	 * |_________|_________|
	 * |    | nnn or addr  |
	 * |____|____|_________|
	 * |    |    | kk/byte |
	 * |____|____|_________|
	 * |    | x  | y  | n  |
	 * |____|____|____|____|
	 * |a char   |a char   |
	 * |____|____|____|____|
	 * |4bit|4bit|4bit|4bit|
	 * |____|____|____|____|
	 * |0101|1101|0110|1100|
	 * |____|____|____|____|
	 * 
	 * 
	 * for eatch iteration, we read the memory of the program, load variables and send it to the function designated by the op_code
	 * this should be tested => opcode = (short)((cpu0.memory + ip  << 8) + cpu0.memory + ip + 1);
	 * switch loop on the op_code, call the function and send arguments (addr, nibble, ect depending of the function, no global variables on that), the cpu is global so shouldn't be sent
	 * the op_code in documentation is "All instructions are 2 bytes long and are stored most-significant-byte first. In memory, the first byte of each instruction should be located at an even addresses. If a program includes sprite data, it should be padded so any instructions following it will be properly situated in RAM."
	 * 
	 * 			
	 */  
	
	op_code = cpu0.memory[cpu0.ip] & 0xf0;
	x = cpu0.memory[cpu0.ip] & 0x0f;
	y = cpu0.memory[cpu0.ip + 1] & 0xf0;
	nibble = cpu0.memory[cpu0.ip + 1] & 0x0f;
	
	addr = (x & 0xf) << 8 | (y & 0xf)  << 4 | (nibble & 0xf) ;
	byte = (y & 0xf)  << 4 | (nibble & 0xf) ;
	
	
	switch(op_code)
	{
		case (dbyte2)0x0000:
		{
			switch(dbyte1)
			{
				case (short)0xE0:
					instruc_1(addr);
				break;
				case (short)0xEE:
					instruc_2();
				break;
			}
		break;

		case (short)0x1000:
		break;
		case (short)0x2000:
		break;
		case (short)0x3000:
		break;
		case (short)0x4000:
		break;
		case (short)0x5000:
		break;
		case (short)0x6000:
		break;
		case (short)0x7000:
		break;
		case (short)0x8000:
		break;
		case (short)0x9000:
		break;
		case (short)0xA000:
		break;
		case (short)0xB000:
		break;
		case (short)0xC000:
		break;
		case (short)0xD000:
		break;
		case (short)0xE000:
		break;
		case (short)0xF000:
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
		
		#ifdef DEBUG
		while(i < file_len + 0x200)
		{
			//we print each nibble of the double byte
			printf("%.02x-", cpu0.memory[i]& 0xff);
			printf("%.02x  ", cpu0.memory[i + 1]& 0xff);

			// Display 4 double bytes per line
			if (i % 16 == 4)
			{
				printf("\n");
			}
			i+= 2 * sizeof(char);
		}
		#endif
		
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
	printf("HERE\n\n");
	
	
	#ifdef DEBUG
	char a = 0;
	char b = 0;
	for (int i = 0 ; i < 10 ; i++)
	{
		a = cpu0.memory[cpu0.ip] & 0xff;
		b = cpu0.memory[cpu0.ip + 1] & 0xff;
		
		/*addr = (x & 0xf) << 8 | (y & 0xf)  << 4 | (nibble & 0xf) ;
		byte = (y & 0xf)  << 8 | (nibble & 0xf) ;
		printf("%x - %x - ", addr, byte);// & 0xffffff);
		printf("[%.02x:%.02x:%.02x]\n", x& 0xf, y& 0xf, nibble& 0xf);*/
		printf("[%1x:%1x:%1x:%1x]\n", a & 0xf0, a & 0x0f, b & 0xf0, b & 0x0f);
		cpu0.ip = cpu0.ip + 2 * sizeof(char);
	}
	#endif
	
	
}
