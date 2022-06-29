// An iterative C program to check if two linked lists are
// identical or not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
};
bool areIdentical(struct Node *a, struct Node *b)
{
	while (a != NULL && b != NULL)
	{
		if (a->data != b->data)
			return false;
		a = a->next;
		b = b->next;
	}

	return (a == NULL && b == NULL);
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Driver program to test above function */
int main()
{
	/* The constructed linked lists are :
	a: 3->2->1
	b: 3->2->1 */
	struct Node *a = NULL;
	struct Node *b = NULL;
	push(&a, 1);
	push(&a, 2);
	push(&a, 3);
	push(&b, 1);
	push(&b, 2);
	push(&b, 3);

	areIdentical(a, b)? printf("Identical"):
						printf("Not identical");

	return 0;
}

