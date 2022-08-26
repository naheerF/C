/* A program to find the largest multiple of 3 from an array of elements */
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue {
	int front;
	int rear;
	int capacity;
	int* array;
} Queue;
Queue* createQueue(int capacity)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->rear = -1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}
int isEmpty(Queue* queue)
{
	return queue->front == -1;
}
void Enqueue(Queue* queue, int item)
{
	queue->array[++queue->rear] = item;
	if (isEmpty(queue))
		++queue->front;
}
int Dequeue(Queue* queue)
{
	int item = queue->array[queue->front];
	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		queue->front++;

	return item;
}
void printArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}
int compareAsc(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}
int compareDesc(const void* a, const void* b)
{
	return *(int*)a < *(int*)b;
}
void populateAux(int* aux, Queue* queue0, Queue* queue1,
				Queue* queue2, int* top)
{
	while (!isEmpty(queue0))
		aux[(*top)++] = Dequeue(queue0);
	while (!isEmpty(queue1))
		aux[(*top)++] = Dequeue(queue1);
	while (!isEmpty(queue2))
		aux[(*top)++] = Dequeue(queue2);
}
int findMaxMultupleOf3(int* arr, int size)
{
	qsort(arr, size, sizeof(int), compareAsc);
	Queue* queue0 = createQueue(size);
	Queue* queue1 = createQueue(size);
	Queue* queue2 = createQueue(size);
	int i, sum;
	for (i = 0, sum = 0; i < size; ++i) {
		sum += arr[i];
		if ((arr[i] % 3) == 0)
			Enqueue(queue0, arr[i]);
		else if ((arr[i] % 3) == 1)
			Enqueue(queue1, arr[i]);
		else
			Enqueue(queue2, arr[i]);
	}
	if ((sum % 3) == 1) {
		if (!isEmpty(queue1))
			Dequeue(queue1);
		else {
			if (!isEmpty(queue2))
				Dequeue(queue2);
			else
				return 0;

			if (!isEmpty(queue2))
				Dequeue(queue2);
			else
				return 0;
		}
	}
	else if ((sum % 3) == 2) {
		if (!isEmpty(queue2))
			Dequeue(queue2);
		else {
			if (!isEmpty(queue1))
				Dequeue(queue1);
			else
				return 0;

			if (!isEmpty(queue1))
				Dequeue(queue1);
			else
				return 0;
		}
	}

	int aux[size], top = 0;
	populateAux(aux, queue0, queue1, queue2, &top);
	qsort(aux, top, sizeof(int), compareDesc);
	printArr(aux, top);

	return top;
}
int main()
{
	int arr[] = { 8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	if (findMaxMultupleOf3(arr, size) == 0)
		printf("Not Possible");

	return 0;
}

