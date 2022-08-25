#include <stdio.h>

void InsertionSort(int a[], int n)	// ���� ���� �Լ� (a�� ������ ���� a++; ����)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = a[i];	// key�� ����
		for (j = i - 1; j >= 0; j--)
		{
			if (key < a[j]) a[j + 1] = a[j];	// key���� ������ ������ ������ ���������� ��ĭ�� �̵�
			else break;
		}
		a[j + 1] = key;	// �� �濡 key�� �ֱ�
	}
}

int main(void)	// (a�� ������ ������ �ƴ� a++; �Ұ���)
{
	int a[] = { 7, 12, 6, 11, 3, 8, 5, 2 };	// ������ ������ �غ�
	int i, n = sizeof(a) / sizeof(int);	// �迭�� �� ���� ���ϱ�

	printf("���� ��: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	InsertionSort(a, n);	// ���� ���� �Լ� ȣ��

	printf("\n���� ��: ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	return 0;
}