#include <stdio.h>
#include <stdlib.h>

/* You would want to remove below 3 lines if your compiler
supports bool, true and false */
#define bool int
#define true 1
#define false 0
struct node {
	int data;
	struct node* left;
	struct node* right;
};
void mirror(struct node* node);
bool isStructSame(struct node* a, struct node* b);
bool isFoldable(struct node* root)
{
	bool res;
	if (root == NULL)
		return true;
	mirror(root->left);
	res = isStructSame(root->left, root->right);
	mirror(root->left);

	return res;
}

bool isStructSame(struct node* a, struct node* b)
{
	if (a == NULL && b == NULL) {
		return true;
	}
	if (a != NULL && b != NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right)) {
		return true;
	}

	return false;
}
void mirror(struct node* node)
{
	if (node == NULL)
		return;
	else {
		struct node* temp;

		/* do the subtrees */
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
int main(void)
{
	/* The constructed binary tree is
		1
	/ \
	2	 3
	\ /
	4 5
*/
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->left->right = newNode(5);

	if (isFoldable(root) == 1) {
		printf("\n tree is foldable");
	}
	else {
		printf("\n tree is not foldable");
	}

	getchar();
	return 0;
}

