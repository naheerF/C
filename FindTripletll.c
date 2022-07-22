#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node* next;
};
void push (struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
bool isSumSorted(struct Node *headA, struct Node *headB,
				struct Node *headC, int givenNumber)
{
	struct Node *a = headA;
	while (a != NULL)
	{
		struct Node *b = headB;
		struct Node *c = headC;
		while (b != NULL && c != NULL)
		{
			int sum = a->data + b->data + c->data;
			if (sum == givenNumber)
			{
			printf ("Triplet Found: %d %d %d ", a->data,
										b->data, c->data);
			return true;
			}
			else if (sum < givenNumber)
				b = b->next;
			else 
				c = c->next;
		}
		a = a->next; 
	}

	printf ("No such triplet");
	return false;
}
int main()
{
	struct Node* headA = NULL;
	struct Node* headB = NULL;
	struct Node* headC = NULL;

	/*create a linked list 'a' 10->15->5->20 */
	push (&headA, 20);
	push (&headA, 4);
	push (&headA, 15);
	push (&headA, 10);
	push (&headB, 10);
	push (&headB, 9);
	push (&headB, 4);
	push (&headB, 2);
	push (&headC, 1);
	push (&headC, 2);
	push (&headC, 4);
	push (&headC, 8);

	int givenNumber = 25;

	isSumSorted (headA, headB, headC, givenNumber);

	return 0;
}

