
#include <stdio.h>
int findNumberOfTriangles(int arr[], int n)
{
	int count = 0,i,j,k;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++)
				if (arr[i] + arr[j] > arr[k]
					&& arr[i] + arr[k] > arr[j]
					&& arr[k] + arr[j] > arr[i])
					count++;
		}
	}
	return count;
}

// Driver code
int main()
{
	int arr[] = { 10, 21, 22, 100, 101, 200, 300 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Total number of triangles possible is %d ",
		findNumberOfTriangles(arr, size));
	return 0;
}


