#include <stdio.h>

int main(void)
{
	int k = 5, * p1, **p2;
	p1 = &k;
	*p1 = 15;
	printf("k: %d \n", k);
	p2 = &p1;
	printf("p2: %d \n", **p2);
	**p2 = *p1 + 10;
	printf("p2: %d \n", **p2);
	printf("p1: %d", *p1);
}