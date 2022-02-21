#include "mySimpleComputer.h"


int a[100];
int memory[100];
int flags;

int sc_memmoryInit(){
	for (int i=0;i<100;i++)
		a[i]=0;
	return 0;
}

int sc_memorySet(int address, int value){
	try{
		if(address<0 || address>99)
			throw 1;
		a[address]=value;
	}
	catch(int warning){
		return warning;
	}
	return 0;
}

int sc_memoryGet (int address, int * value){	
	try{
		if(address<0 || address>99)
			throw 1;
		value = &memory[address];
	}
	catch(int warning){
		return warning;
	}
	return 0;
}
//O_RDONLY - read
//O_WRONLY - draw
//O_RDWR   - draw & read
int sc_memorySave (char * filename){
	int file = open(filename,O_WRONLY);
	write(file,memory,sizeof(int)*SIZE);
	close(file);
	return 0;
}

int sc_memoryLoad (char * filename){
	int file = open(filename,O_RDONLY);
	read(file,memory,sizeof(int)*SIZE);
	close(file);
	return 0;
}

int sc_regInit (void){
	flags = 0;
	return 0;
}

int sc_regSet (int registr, int value){
	try{
		if(registr<1 || registr>5)
			throw -1;
	}
	catch(int warning){
		return warning;
	}
	if(value)
		flags |= (1 << registr);
	else
		flags &= (~(1<<registr));
	return 0;
}

int sc_regGet (int registr, int * value){
	try{
		if(registr<1 || registr>5)
			throw -1;
		*value = ((flags >> registr)&0x1);
	}
	catch(int warning){
		return warning;
	}
	return 0;
}

int sc_commandEncode (int command, int operand, int * value){
	try{
		if(operand > 0x7F)
			throw -1;
		if (std::binary_search(std::begin(COMMANDS), std::end(COMMANDS), command))
			*value = (command << 7)|operand;
		else
			throw -1;
	}
	catch(int warning){
		return warning;
	}
	return 0;
}

int sc_commandDecode (int value, int * command, int * operand){
	int tempCommand;
	try{
		if(((value >> 14) & 1) != 0)
			throw -1;
		if (std::binary_search(std::begin(COMMANDS), std::end(COMMANDS), tempCommand)) {
            		*command = tempCommand;
            		*operand = value & 0x7F;
            	}
		else
			throw -1;
	}
	catch(int warning){
		return warning;
	}
	return 0;
}

