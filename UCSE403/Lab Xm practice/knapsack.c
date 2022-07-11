#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int knapsack(int W, int wt[], int val[], int n)
{
	int knap[n + 1][W + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)
			{
				knap[i][j] = 0;
			}
			else if (wt[i - 1] <= j)
			{
				knap[i][j] = max(val[i - 1] + knap[i - 1][j - wt[i - 1]], knap[i - 1][j]);
			}
			else
			{
				knap[i][j] = knap[i - 1][j];
			}
		}
	}
	return knap[n][W];
}

int main()
{
	int val[] = {1, 6, 18, 22, 28};
	int wt[] = {1, 2, 5, 6, 7};
	int W = 11;
	int n = sizeof(val) / sizeof(val[0]);
	printf("The solution is : %d", knapsack(W, wt, val, n));
	return 0;
}