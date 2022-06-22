// C Program to shuffle a given array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printArray (int arr[], int n)
{
	int i;
	for ( i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void randomize ( int arr[], int n )
{
int i;
	srand ( time(NULL) );
	for ( i = n-1; i > 0; i--)
	{
		int j = rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
}

// Driver program to test above function.
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr)/ sizeof(arr[0]);
	randomize (arr, n);
	printArray(arr, n);

	return 0;
}

