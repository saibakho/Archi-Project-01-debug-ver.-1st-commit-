#include <stdio.h>
#include <stdlib.h>
#include "trans.h"
#include "inst.h"


void scanInst(void)
{
	FILE * file = fopen("iimage.bin", "r");
	if (!file) { printf("No iimage.bin"); exit(1); }
	unsigned char ch[4];
	unsigned int _pc;
	char buffer[32];
//= get PC address    ========================================
	for (int i = 0; i < 4; i++) {
		fscanf(file, "%c", &ch[i]);
		intToBin((unsigned int)ch[i], &buffer[24 - i * 8], 8);
	}	PC = iPC = binToUnsInt(buffer, 31, 0);
	printf("PC      : %#010x\n", iPC);
//= get instructions number ==================================
	for (int i = 0; i < 4; i++) {
		fscanf(file, "%c", &ch[i]);
		intToBin((unsigned int)ch[i], &buffer[24 - i * 8], 8);
	}	instNum = binToUnsInt(buffer, 31, 0);
	inst = malloc( sizeof(unsigned int) * instNum );
	printf("instNum : %#010x\n", instNum);
//= translate to MIPS ========================================
	for (int i = 0; i < instNum; i++) {
		for (int j = 0; j < 4; j++) {
			fscanf(file, "%c", &ch[j]);
			intToBin((unsigned int)ch[j], &buffer[24 - j * 8], 8);
		}	inst[i] = binToUnsInt(buffer, 31, 0);
		printf("[%#010x] : ", PC += 4);
		printf("0x%08x\n", inst[i]);
	}	fclose(file);
}
void scanMem(void)
{
	FILE * file = fopen("dimage.bin", "r");
	if (!file) { printf("No dimage.bin"); exit(1); }
	unsigned char ch[4];
	char buffer[32];
//= get stack pointer ========================================
	for (int i = 0; i < 32; i++)	reg[i] = 0;
	for (int i = 0; i < 4; i++) {
		fscanf(file, "%c", &ch[i]);
		intToBin((unsigned int)ch[i], &buffer[24 - i * 8], 8);
	}	SP = binToUnsInt(buffer, 31, 0);
	printf("$sp    : %#010x\n", SP);
//= get memory number ========================================
	for (int i = 0; i < 4; i++) {
		fscanf(file, "%c", &ch[i]);
		intToBin((unsigned int)ch[i], &buffer[24 - i * 8], 8);
	}	memNum = binToUnsInt(buffer, 31, 0);
	printf("memNum : %#010x\n", memNum);
//= get memory[1024]  ========================================
	for (int i = 0; i < memNum; i++) {
		for (int j = 0; j < 4; j++) {
			fscanf(file, "%c", &ch[j]);
			intToBin((unsigned int)ch[j], &buffer[24 - j * 8], 8);
		}	memory[i] = binToUnsInt(buffer, 31, 0);	// beware of Memory overflow
		printf("[0x%08x] %#010x\n", i*4, memory[i]);
	}	fclose(file);
}