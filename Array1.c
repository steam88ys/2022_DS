#include <stdio.h>
#define SIZE 11

int main(void)
{

	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
	int index, i;
	char value;

	printf("삽입위치 : ");
	scanf_s("%d", &index);	// 입력 후 엔터키 까지 들어감
	getchar();	// 한문자 입력 받기

	printf("삽인문자 : ");
	scanf_s("%c", &value, 1);	// 문자 하나 입력

	i = SIZE - 1;

	while (i > index) {
		a[i] = a[i - 1];
		i--;
	}
	a[index] = value;
	a[SIZE - 1] = '\0';

	printf("삽입결과 : %s \n", a);

	return 0;

}