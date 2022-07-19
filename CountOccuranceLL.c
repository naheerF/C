#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 
int count(struct Node* head, int search_for) 
{ 
	struct Node* current = head; 
	int count = 0; 
	while (current != NULL) { 
		if (current->data == search_for) 
			count++; 
		current = current->next; 
	} 
	return count; 
} 
int main() 
{ 
	struct Node* head = NULL; 

	/* Use push() to construct below list 
	1->2->1->3->1 */
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	printf("count of 1 is %d", count(head, 1)); 
	return 0; 
} 

