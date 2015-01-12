//0nnn - SYS addr
instruc_1(short addr)
{
	cpu0.ip = addr;
}

//00E0 - CLS
instruc_2()
{

}

//00EE - RET
instruc_3()
{

}

//1nnn - JP addr
instruc_4()
{

}

//2nnn - CALL addr
instruc_5()
{

}

//3xkk - SE Vx, byte
instruc_6()
{

}

//4xkk - SNE Vx, byte
instruc_7()
{

}

//5xy0 - SE Vx, Vy
instruc_8()
{

}

//6xkk - LD Vx, byte
instruc_9()
{

}

//7xkk - ADD Vx, byte
instruc_10()
{

}

//8xy0 - LD Vx, Vy
instruc_11()
{

}

//8xy1 - OR Vx, Vy
instruc_12()
{

}

//8xy2 - AND Vx, Vy
instruc_13()
{

}

//8xy3 - XOR Vx, Vy
instruc_14()
{

}

//8xy4 - ADD Vx, Vy
instruc_15()
{

}

//8xy5 - SUB Vx, Vy
instruc_16()
{

}

//8xy6 - SHR Vx {, Vy}
instruc_17()
{

}

//8xy7 - SUBN Vx, Vy
instruc_18()
{

}

//8xyE - SHL Vx {, Vy}
instruc_19()
{

}

//9xy0 - SNE Vx, Vy
instruc_20()
{

}

//Annn - LD I, addr
instruc_21()
{

}

//Bnnn - JP V0, addr
instruc_22()
{

}

//Cxkk - RND Vx, byte
instruc_23()
{

}

//Dxyn - DRW Vx, Vy, nibble
instruc_24()
{

}

//Ex9E - SKP Vx
instruc_25()
{

}

//ExA1 - SKNP Vx
instruc_26()
{

}

//Fx07 - LD Vx, DT
instruc_27()
{

}

//Fx0A - LD Vx, K
instruc_28()
{

}

//Fx15 - LD DT, Vx
instruc_29()
{

}

//Fx18 - LD ST, Vx
instruc_30()
{

}

//Fx1E - ADD I, Vx
instruc_31()
{

}

//Fx29 - LD F, Vx
instruc_32()
{

}

//Fx33 - LD B, Vx
instruc_33()
{

}

//Fx55 - LD [I], Vx
instruc_34()
{

}

//Fx65 - LD Vx, [I]
instruc_35()
{

}

