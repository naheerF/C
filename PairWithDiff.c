// C program to find a pair with the given difference
#include <stdio.h>
int findPair(int arr[], int size, int n)
{
	int i = 0;
	int j = 1;
	while (i<size && j<size)
	{
		if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n))
		{
			printf("Pair Found: (%d, %d)", arr[i], arr[j]);
			return 1;
		}
		else if (arr[j]-arr[i] < n)
			j++;
		else
			i++;
	}

	printf("No such pair");
	return 0;
}

int main()
{
	int arr[] = {1, 8, 30, 40, 100};
	int size = sizeof(arr)/sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	return 0;
}

