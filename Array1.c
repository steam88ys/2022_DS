#include <stdio.h>
#define SIZE 11

int main(void)
{

	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
	int index, i;
	char value;

	printf("������ġ : ");
	scanf_s("%d", &index);	// �Է� �� ����Ű ���� ��
	getchar();	// �ѹ��� �Է� �ޱ�

	printf("���ι��� : ");
	scanf_s("%c", &value, 1);	// ���� �ϳ� �Է�

	i = SIZE - 1;

	while (i > index) {
		a[i] = a[i - 1];
		i--;
	}
	a[index] = value;
	a[SIZE - 1] = '\0';

	printf("���԰�� : %s \n", a);

	return 0;

}