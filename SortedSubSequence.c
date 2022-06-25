// C program to find a sorted
// sub-sequence of size 3
#include <stdio.h>
void find3Numbers(int arr[], int n)
{
	int max = n - 1;
	int min = 0;
	int i;
	int* smaller = new int[n];
	smaller[0] = -1;
	for (i = 1; i < n; i++) {
		if (arr[i] <= arr[min]) {
			min = i;
			smaller[i] = -1;
		}
		else
			smaller[i] = min;
	}
	int* greater = new int[n];
	greater[n - 1] = -1;
	for (i = n - 2; i >= 0; i--) {
		if (arr[i] >= arr[max]) {
			max = i;
			greater[i] = -1;
		}
		else
			greater[i] = max;
	}
	for (i = 0; i < n; i++) {
		if (smaller[i] != -1 && greater[i] != -1) {
			printf("%d %d %d", arr[smaller[i]],
				arr[i], arr[greater[i]]);
			return;
		}
	}
	printf("No such triplet found");
	delete[] smaller;
	delete[] greater;

	return;
}

// Driver program to test above function
int main()
{
	int arr[] = { 12, 11, 10, 5, 6, 2, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	find3Numbers(arr, n);
	return 0;
}

