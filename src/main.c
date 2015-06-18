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
	
	cpu0.dbyte1 = cpu0.memory[cpu0.ip] & 0xff;
	cpu0.dbyte2 = cpu0.memory[cpu0.ip + 1] & 0xff;
	
	#ifdef DEBUG
		printf("[%1x:%1x:%1x:%1x]\n", cpu0.dbyte1 & 0xf0, cpu0.dbyte1 & 0x0f, cpu0.dbyte2 & 0xf0, cpu0.dbyte2 & 0x0f);
	#endif
	
	
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
	 * 
	op_code = cpu0.memory[cpu0.ip] & 0xf0;
	x = cpu0.memory[cpu0.ip] & 0x0f;
	y = cpu0.memory[cpu0.ip + 1] & 0xf0;
	nibble = cpu0.memory[cpu0.ip + 1] & 0x0f;
	
	addr = (x & 0xf) << 8 | (y & 0xf)  << 4 | (nibble & 0xf) ;
	byte = (y & 0xf)  << 4 | (nibble & 0xf) ;
	 */  
	
	switch(cpu0.dbyte1 & 0xf0)
	{
		case 0x00:
		{
			switch(cpu0.dbyte2)
			{
				case (char)0xE0:
					#ifdef DEBUG
						printf("INSTRUCT_2\n");
					#endif
					instruc_2(1);
				break;
				case (char)0xEE:
					#ifdef DEBUG
						printf("INSTRUCT_3\n");
					#endif
					instruc_3();
				break;
				default:
					#ifdef DEBUG
						printf("INSTRUCT_1\n");
					#endif
					instruc_1();
				break;
			}
		break;

		case (char)0x10:
			#ifdef DEBUG
				printf("INSTRUCT_4\n");
			#endif
			instruc_4();
		break;
		case (char)0x20:
			#ifdef DEBUG
				printf("INSTRUCT_5\n");
			#endif
			instruc_5();
		break;
		case (char)0x30:
			#ifdef DEBUG
				printf("INSTRUCT_6\n");
			#endif
			instruc_6();
		break;
		case (char)0x40:
			#ifdef DEBUG
				printf("INSTRUCT_7\n");
			#endif
			instruc_7();
		break;
		case (char)0x50:
			#ifdef DEBUG
				printf("INSTRUCT_8\n");
			#endif
			instruc_8();
		break;
		case (char)0x60:
			#ifdef DEBUG
				printf("INSTRUCT_9\n");
			#endif
			instruc_9();
		break;
		case (char)0x70:
			#ifdef DEBUG
				printf("INSTRUCT_10\n");
			#endif
			instruc_10();
		break;
		case (char)0x80:
			switch(cpu0.dbyte2 & 0x0f)
			{
				case 0x0:
					#ifdef DEBUG
						printf("INSTRUCT_11\n");
					#endif
					instruc_11();
				break;
				case 0x1:
					#ifdef DEBUG
						printf("INSTRUCT_12\n");
					#endif
					instruc_12();
				break;
				case 0x2:
					#ifdef DEBUG
						printf("INSTRUCT_13\n");
					#endif
					instruc_13();
				break;
				case 0x3:
					#ifdef DEBUG
						printf("INSTRUCT_14\n");
					#endif
					instruc_14();
				break;
				case 0x4:
					#ifdef DEBUG
						printf("INSTRUCT_15\n");
					#endif
					instruc_15();
				break;
				case 0x5:
					#ifdef DEBUG
						printf("INSTRUCT_16\n");
					#endif
					instruc_16();
				break;
				case 0x6:
					#ifdef DEBUG
						printf("INSTRUCT_17\n");
					#endif
					instruc_17();
				break;
				case 0x7:
					#ifdef DEBUG
						printf("INSTRUCT_18\n");
					#endif
					instruc_18();
				break;
				case 0xE:
					#ifdef DEBUG
						printf("INSTRUCT_19\n");
					#endif
					instruc_19();
				break;
				default:
					printf("ERROR IN THE DISPATCHER !\n");
				break;
			}
				
		break;
		case (char)0x90:
			#ifdef DEBUG
				printf("INSTRUCT_20\n");
			#endif
			instruc_20();
		break;
		case 0xa0:
			#ifdef DEBUG
				printf("INSTRUCT_21\n");
			#endif
			instruc_21();
		break;
		case (char)0xb0:
			#ifdef DEBUG
				printf("INSTRUCT_22\n");
			#endif
			instruc_22();
		break;
		case (char)0xc0:
			#ifdef DEBUG
				printf("INSTRUCT_23\n");
			#endif
			instruc_23();
		break;
		case (char)0xd0:
			#ifdef DEBUG
				printf("INSTRUCT_24\n");
			#endif
			instruc_24();
		break;
		case (char)0xe0:
			switch(cpu0.dbyte2)
			{
				case (char)0x9E:
					#ifdef DEBUG
						printf("INSTRUCT_25\n");
					#endif
					instruc_25();
				break;
				case (char)0xA1:
					#ifdef DEBUG
						printf("INSTRUCT_26\n");
					#endif
					instruc_26();
				break;
				default:
					printf("ERROR IN THE DISPATCHER !\n");
				break;
			}
		break;
		case 0xf0:
			switch(cpu0.dbyte2)
			{
				case 0x07:
					#ifdef DEBUG
						printf("INSTRUCT_27\n");
					#endif
					instruc_27();
				break;
				case 0x0A:
					#ifdef DEBUG
						printf("INSTRUCT_28\n");
					#endif
					instruc_28();
				break;
				case 0x15:
					#ifdef DEBUG
						printf("INSTRUCT_29\n");
					#endif
					instruc_29();
				break;
				case 0x18:
					#ifdef DEBUG
						printf("INSTRUCT_30\n");
					#endif
					instruc_30();
				break;
				case 0x1E:
					#ifdef DEBUG
						printf("INSTRUCT_31\n");
					#endif
					instruc_31();
				break;
				case 0x29:
					#ifdef DEBUG
						printf("INSTRUCT_32\n");
					#endif
					instruc_32();
				break;
				case 0x33:
					#ifdef DEBUG
						printf("INSTRUCT_33\n");
					#endif
					instruc_33();
				break;
				case 0x55:
					#ifdef DEBUG
						printf("INSTRUCT_34\n");
					#endif
					instruc_34();
				break;
				case 0x65:
					#ifdef DEBUG
						printf("INSTRUCT_35\n");
					#endif
					instruc_35();
				break;
				default:
					printf("ERROR IN THE DISPATCHER !\n");
				break;
			}
		break;
		default:
			printf("ERROR IN THE DISPATCHER !\n");
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
	
	for(int i = 0 ; i < 20 ; i++)
	{
		emulate();
		cpu0.ip = 2 * sizeof(char) + cpu0.ip;
	}
	#ifdef DEBUG
	/*
	char a = 0;
	char b = 0;
	for (int i = 0 ; i < 10 ; i++)
	{
		a = cpu0.memory[cpu0.ip] & 0xff;
		b = cpu0.memory[cpu0.ip + 1] & 0xff;
		
		addr = (x & 0xf) << 8 | (y & 0xf)  << 4 | (nibble & 0xf) ;
		byte = (y & 0xf)  << 8 | (nibble & 0xf) ;
		printf("%x - %x - ", addr, byte);// & 0xffffff);
		printf("[%.02x:%.02x:%.02x]\n", x& 0xf, y& 0xf, nibble& 0xf);
		printf("[%1x:%1x:%1x:%1x]\n", a & 0xf0, a & 0x0f, b & 0xf0, b & 0x0f);
		cpu0.ip = cpu0.ip + 2 * sizeof(char);
	}*/
	#endif
	
	
}
