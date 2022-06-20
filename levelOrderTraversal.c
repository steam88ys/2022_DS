#include<stdio.h>
#include<malloc.h>

//����Ʈ���� ����� ���
struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node** queue;

int rear = -1, front = 0;
int nodeCnt = 0;

//��� ���� �Լ�
struct node* newNode(char data) {
	struct node* p;

	p = (struct node*)malloc(sizeof(struct node));
	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;

	return p;
}

//����Ʈ�� ���� �Լ�
struct node* createBinaryTree(char a[]) {
	struct node* p;

	p = newNode(a[0]);
	p->llink = newNode(a[1]);
	p->rlink = newNode(a[2]);
	p->llink->llink = newNode(a[3]);
	p->llink->rlink = newNode(a[4]);
	p->rlink->llink = newNode(a[5]);
	p->rlink->rlink = newNode(a[6]);
	p->llink->llink->rlink = newNode(a[7]);
	p->rlink->llink->llink = newNode(a[8]);
	p->rlink->llink->llink->llink = newNode(a[9]);

	return p;
}

//ť�� ��� �ּ� ����
void add(struct node* p) {
	if (rear == nodeCnt - 1) {
		printf("\nQudue is Full!");
		return;
	}
	queue[++rear] = p;
}

//ť�� �����
struct node* delete(void) {
	if (rear < front) {
		printf("\nQudue is Empty! ������ �Ϸ���!!");
		return NULL;
	}
	return queue[front++];
}

//����Ʈ�� ��� ��� �Ҹ�
void deleteAll(struct node* p) {
	if (p != NULL) {
		deleteAll(p->llink);
		deleteAll(p->rlink);
		free(p);
	}
}

void levelOrder(struct node* p) {
	printf("%c", p->data);
	add(p);
	while ((p = delete()) != NULL) {
		if (p->llink != NULL) {
			printf("->%c", p->llink->data);
			add(p->llink);
		}
		if (p->rlink != NULL) {
			printf("->%c", p->rlink->data);
			add(p->rlink);
		}
	}
}

int main(void) {
	char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	struct node* root;

	printf("���� Ʈ�� ������ �Ϸ���!");
	root = createBinaryTree(a);
	nodeCnt = sizeof(a) / sizeof(char);

	printf("\n\n���� ť�� �غ���!");
	queue = (struct node**)malloc(sizeof(struct node*) * nodeCnt);

	printf("\n\n���� ���� ���� ���: ");
	levelOrder(root);

	deleteAll(root);
	printf("\n\n���� Ʈ�� �Ҹ��!\n");

	return 0;
}
