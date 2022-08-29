#include <stdio.h>

void shellSort(int a[], int n)
{
	int i, j, key, t;	// t�� ������

	for (t = n / 2; t >= 1; t/=2) {	// ������ �������� �پ��
		for (i = t; i < n; i++)
		{
			key = a[i];	// key�� ����
			for (j = i - t; j >= 0; j-=t)	// ���ݸ�ŭ �������� �̵�
			{
				if (key < a[j]) a[j + t] = a[j];	// ���� ���� Ŭ �� �̵�
				else break;
			}
			a[j + t] = key;	// �� �濡 key�� �ֱ�
		}
	}
}

int main(void)
{
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };	// ������ ������ �غ�
	int i, n = sizeof(a) / sizeof(int);	// �迭�� �� ���� ���ϱ�

	printf("���� ��: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	shellSort(a, n);

	printf("\n���� ��: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	return 0;
}