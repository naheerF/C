#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray(int stream[], int n)
{int i;
	for ( i = 0; i < n; i++)
		printf("%d ", stream[i]);
	printf("\n");
}
void selectKItems(int stream[], int n, int k)
{
	int i; 
	int reservoir[k];
	for (i = 0; i < k; i++)
		reservoir[i] = stream[i];
	srand(time(NULL));
	for (; i < n; i++)
	{
		// Pick a random index from 0 to i.
		int j = rand() % (i+1);
		if (j < k)
		reservoir[j] = stream[i];
	}

	printf("Following are k randomly selected items \n");
	printArray(reservoir, k);
}
int main()
{
	int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int n = sizeof(stream)/sizeof(stream[0]);
	int k = 5;
	selectKItems(stream, n, k);
	return 0;
}

