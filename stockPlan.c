// C program for brute force method to calculate stock span values
#include <stdio.h>
void calculateSpan(int price[], int n, int S[])
{
	int i,j;
	S[0] = 1;
	for (i = 1; i < n; i++) {
		S[i] = 1; 
		for ( j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
			S[i]++;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
int main()
{
	int price[] = { 10, 4, 5, 90, 120, 80 };
	int n = sizeof(price) / sizeof(price[0]);
	int S[n];
	calculateSpan(price, n, S);
	printArray(S, n);

	return 0;
}

