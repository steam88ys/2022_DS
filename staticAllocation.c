#include <stdio.h>
#define SIZE 1000000

int main(void) {
	// ������Ʈ �Ӽ� -> ��Ŀ -> �ý��� -> ���� ���� ũ�� �Ǵ� �� ���� ũ��
	int a[SIZE] = {10, };	// �迭 a�� 4Mb ũ�⸦ �䱸��

	printf("%d\n", a[0]);

	return 0;
}