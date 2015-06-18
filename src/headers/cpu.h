typedef  struct Cpu Cpu;
struct Cpu
{
        char memory[2048]; //4096 block of 8 bits
        short ip ; //instruction pointeur of the cpu
        char registers[16]; //16 registers of 8 bits
        char register_I; //the I register (like I robot, but register verion. REGISTER GONNA RULES ZE WORLD !)
        
        //we don't want to declare you everywhere !
		char dbyte1;
		char dbyte2;
};

extern Cpu cpu0;
