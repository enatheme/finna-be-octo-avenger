//inclusion of instructions.h
#ifndef INC_INSTRUCTIONS
#define INC_INSTRUCTIONS
#include "headers/instructions.h"
#endif


//0nnn - SYS addr
void instruc_1()
{
}

//00E0 - CLS
void instruc_2()
{

}

//00EE - RET
void instruc_3()
{
	//cpu0.ip = (cpu0.dbyte1 & 0xff) << 4 | (cpu0.dbyte2 & 0xffff);
	printf("\n ip = %x\n", cpu0.ip);

}

//1nnn - JP addr
void instruc_4()
{

}

//2nnn - CALL addr
void instruc_5()
{

}

//3xkk - SE Vx, byte
void instruc_6()
{

}

//4xkk - SNE Vx, byte
void instruc_7()
{

}

//5xy0 - SE Vx, Vy
void instruc_8()
{

}

//6xkk - LD Vx, byte
void instruc_9()
{

}

//7xkk - ADD Vx, byte
void instruc_10()
{

}

//8xy0 - LD Vx, Vy
void instruc_11()
{

}

//8xy1 - OR Vx, Vy
void instruc_12()
{

}

//8xy2 - AND Vx, Vy
void instruc_13()
{

}

//8xy3 - XOR Vx, Vy
void instruc_14()
{

}

//8xy4 - ADD Vx, Vy
void instruc_15()
{

}

//8xy5 - SUB Vx, Vy
void instruc_16()
{

}

//8xy6 - SHR Vx {, Vy}
void instruc_17()
{

}

//8xy7 - SUBN Vx, Vy
void instruc_18()
{

}

//8xyE - SHL Vx {, Vy}
void instruc_19()
{

}

//9xy0 - SNE Vx, Vy
void instruc_20()
{

}

//Annn - LD I, addr
void instruc_21()
{

}

//Bnnn - JP V0, addr
void instruc_22()
{

}

//Cxkk - RND Vx, byte
void instruc_23()
{

}

//Dxyn - DRW Vx, Vy, nibble
void instruc_24()
{

}

//Ex9E - SKP Vx
void instruc_25()
{

}

//ExA1 - SKNP Vx
void instruc_26()
{

}

//Fx07 - LD Vx, DT
void instruc_27()
{

}

//Fx0A - LD Vx, K
void instruc_28()
{

}

//Fx15 - LD DT, Vx
void instruc_29()
{

}

//Fx18 - LD ST, Vx
void instruc_30()
{

}

//Fx1E - ADD I, Vx
void instruc_31()
{

}

//Fx29 - LD F, Vx
void instruc_32()
{

}

//Fx33 - LD B, Vx
void instruc_33()
{

}

//Fx55 - LD [I], Vx
void instruc_34()
{

}

//Fx65 - LD Vx, [I]
void instruc_35()
{

}

