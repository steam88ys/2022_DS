#include <stdio.h>

void shellSort(int a[], int n)
{
	int i, j, key, t;	// t는 간격임

	for (t = n / 2; t >= 1; t/=2) {	// 간격이 절반으로 줄어듦
		for (i = t; i < n; i++)
		{
			key = a[i];	// key값 설정
			for (j = i - t; j >= 0; j-=t)	// 간격만큼 왼쪽으로 이동
			{
				if (key < a[j]) a[j + t] = a[j];	// 왼쪽 값이 클 때 이동
				else break;
			}
			a[j + t] = key;	// 빈 방에 key값 넣기
		}
	}
}

int main(void)
{
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };	// 정렬할 데이터 준비
	int i, n = sizeof(a) / sizeof(int);	// 배열의 방 개수 구하기

	printf("정렬 전: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	shellSort(a, n);

	printf("\n정렬 후: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	return 0;
}