#include <stdio.h>

void InsertionSort(int a[], int n)	// 삽입 정렬 함수 (a는 포인터 변수 a++; 가능)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = a[i];	// key값 설정
		for (j = i - 1; j >= 0; j--)
		{
			if (key < a[j]) a[j + 1] = a[j];	// key값이 오른쪽 값보다 작으면 오른쪽으로 한칸씩 이동
			else break;
		}
		a[j + 1] = key;	// 빈 방에 key값 넣기
	}
}

int main(void)	// (a는 포인터 변수가 아니 a++; 불가능)
{
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };	// 정렬할 데이터 준비
	int i, n = sizeof(a) / sizeof(int);	// 배열의 방 개수 구하기

	printf("정렬 전: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	InsertionSort(a, n);	// 삽입 정렬 함수 호출

	printf("\n정렬 후: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	return 0;
}