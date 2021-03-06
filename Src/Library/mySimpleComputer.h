#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


const static int SIZE = 100;
const int COMMANDS[38] = {
            0xA,  0xB, 0x14, 0x15, 0x1E, 0x1F, 0x20, 0x21,
            0x28, 0x29, 0x2A, 0x2B, 0x33, 0x34, 0x35, 0x36,
            0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E,
            0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
            0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C};

int sc_memmoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet (int address, int * value);
int sc_memorySave (char * filename);
int sc_memoryLoad (char * filename);
int sc_regInit (void);
int sc_regSet (int registr, int value);
int sc_regGet (int registr, int * value);
int sc_commandEncode (int command, int operand, int * value);
int sc_commandDecode (int value, int * command, int * operand);
