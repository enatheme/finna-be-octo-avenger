#make file for this project
#enatheme
#enatheme@enatheme.org
CC=gcc
CF= -DDEBUG -std=c99
LDFLAGS= -lm
#LDFLAGS= -lpthread
EXEC=chip8  #if we want to launch an execution directly


all: chip8

chip8: main.o cpu.o instructions.o
	$(CC) -o bin/chip8 tmp/main.o tmp/cpu.o tmp/instructions.o $(LDFLAGS)

main.o: src/main.c
	$(CC) -o tmp/main.o -c src/main.c $(CF)

cpu.o: src/headers/cpu.h src/cpu.c
	$(CC) -o tmp/cpu.o -c src/cpu.c $(CF)

instructions.o: src/headers/instructions.h src/instructions.c 
	$(CC) -o tmp/instructions.o -c src/instructions.c $(CF)


clean:
	rm tmp/*.o

mrproper: clean
	rm bin/crypto
