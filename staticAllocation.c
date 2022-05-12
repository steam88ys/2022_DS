#include <stdio.h>
#define SIZE 1000000

int main(void) {
	// 프로젝트 속성 -> 링커 -> 시스템 -> 스택 예약 크기 또는 힙 예약 크기
	int a[SIZE] = {10, };	// 배열 a는 4Mb 크기를 요구함

	printf("%d\n", a[0]);

	return 0;
}