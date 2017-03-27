#include <stdio.h>

unsigned int binToInt(char bin[], int head, int tail)
{
	unsigned int sum = 0, power = 1;
	unsigned int shamt = head - tail;
	while (tail <= head) {
		sum += ( bin[tail++] == '1' ? 1 : 0 ) * power;
		power *= 2;
	}
	if ( (sum >> shamt ) == 1 )
		sum = sum | ( -1 << ( shamt + 1 ) );
	return sum;
}
void intToBin(unsigned int num, char bin[])
{
	for (int i = 0; i < 32; i++) {
		bin[i] = num%2 == 1 ? '1' : '0' ;
		num/=2;
	}
}
void printBin(char bin[])
{
	for (int i = 31; i >= 0; i--) {
		if (i%4 == 0)
			printf("%c ", bin[i]);
		else
			printf("%c", bin[i]);
	}
	printf("\n");
}
int isOverflow(int a, int b, int sum)
{
	if (a > 0 && b > 0)
		return sum < 0 ? 1 : 0 ;
	else if (a < 0 && b < 0)
		return sum > 0 ? 1 : 0 ;
	else return 0;
}
int main (void)
{
	int n = 2;
	char buffer[32];
	int a = 0x7fffffff;
	int b = 1235;

	printf("    a = %12d    ", a);
	intToBin(a, buffer);
	printBin(buffer);
	printf("    b = %12d    ", b);
	intToBin(b, buffer);
	printBin(buffer);
	printf("   b = %12d    ", -b);
	intToBin(b, buffer);
	printBin(buffer);
	printf("a - b = %12d    ", a + b);
	intToBin(a + b, buffer);
	printBin(buffer);
	if (isOverflow(a, b, a + b))
		printf("[Overflow]\n");
	else
		printf("[Correct]\n");
	
	return 0;
}
