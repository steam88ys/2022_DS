#include <stdio.h>
#include <stdlib.h>	// malloc

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* createNode(char data) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	// ����ü nodeũ�� ���ؼ� ���� �Ҵ����ְ� ����� �ּҸ� ���ؼ� p�� �־���

	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
}

void delete(struct node* p) {
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		printf("%c  ", p->data);
		free(p);
	}
}

void preOrder(struct node* p) {	// ��������		D L R
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {	// ��������		L D R
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {	// ��������		L R D
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c  ", p->data);
	}
}

int main(void) {
	struct node* root = createNode('A');	// root�� ��0�� ��
	root->llink = createNode('B');
	root->rlink = createNode('C');
	root->llink->llink = createNode('D');
	root->llink->rlink = createNode('E');
	root->rlink->llink = createNode('F');
	root->rlink->rlink = createNode('G');
	root->llink->rlink->llink = createNode('H');

	printf("���� ����(preOrder)  : ");
	preOrder(root); printf("\n");
	printf("���� ����(inOrder)   : ");
	inOrder(root); printf("\n");
	printf("���� ����(postOrder) : ");
	postOrder(root); printf("\n");

	printf("������� ���� : ");
	delete(root);

	return 0;
}