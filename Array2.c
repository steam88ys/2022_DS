#include <stdio.h>
#define SIZE 11

int main(void)
{

	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
	int index, i;

	printf("삭제위치 : ");
	scanf_s("%d", &index);	// 입력 후 엔터키 까지 들어감
	getchar();	// 한문자 입력 받기

	for (i = index; i < SIZE - 1; i++) {
		a[i] = a[i + 1];
	}

	printf("삭제결과 : %s \n", a);

	return 0;

}