#include <stdio.h>
#include <stdlib.h>	// malloc

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* createNode(char data) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	// 구조체 node크기 구해서 동적 할당해주고 노드의 주소를 구해서 p에 넣어줌

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

void preOrder(struct node* p) {	// 전위운행		D L R
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {	// 중위운행		L D R
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {	// 후위운행		L R D
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c  ", p->data);
	}
}

int main(void) {
	struct node* root = createNode('A');	// root에 별0이 들어감
	root->llink = createNode('B');
	root->rlink = createNode('C');
	root->llink->llink = createNode('D');
	root->llink->rlink = createNode('E');
	root->rlink->llink = createNode('F');
	root->rlink->rlink = createNode('G');
	root->llink->rlink->llink = createNode('H');

	printf("전위 운행(preOrder)  : ");
	preOrder(root); printf("\n");
	printf("중위 운행(inOrder)   : ");
	inOrder(root); printf("\n");
	printf("후위 운행(postOrder) : ");
	postOrder(root); printf("\n");

	printf("사라지는 순서 : ");
	delete(root);

	return 0;
}