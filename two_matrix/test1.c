#include <stdio.h>

int main() {
	//int n=3;
	int arr_temp[n][n];
	int arr[2][2] = {{1, 2}, {3, 4}};
	//int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr_temp[j][n - 1 - i] = arr[i][j];
			printf("arr_temp[%d][%d] = %d arr_temp[%d][%d] = %d\n",
					j, n - 1 - i, arr_temp[j][n - 1 - i],
					i, j, arr[i][j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = arr_temp[i][j];
		}
	}
}
