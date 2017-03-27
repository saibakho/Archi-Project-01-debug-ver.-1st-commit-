#include <stdio.h>

int a[7];
int tree(int index)
{
	if (index > 6)
		return 0;
	return tree(index*2+1) + tree(2*(index+1)) + a[index];
}
int main(void)
{
	for (int i = 0; i < 7; i++)	a[i] = i;
	printf("tree(0) = %d\n", tree(0));

	return 0;
}