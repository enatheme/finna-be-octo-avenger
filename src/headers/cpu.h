typedef  struct Cpu Cpu;
struct Cpu
{
        char memory[4096]; //4096 block of 8 bits
        short ip ; //instruction pointeur of the cpu
        char registers[16]; //16 registers of 8 bits
        short register_I; //the I register (like I robot, but register verion. REGISTER GONNA RULES ZE WORLD !)
        short sp;//stack pointer
        short bp;//base pointer
        
        //we don't want to declare you everywhere !
		char dbyte1;
		char dbyte2;
};

extern Cpu cpu0;


void stack_12(short input);
void stack_8(char input);
void dec_sp();
void inc_sp();
