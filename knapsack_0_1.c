#include <stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int wt[], int val[], int N, int W)
{
	int i, w;
	int K[N + 1][W + 1];

	for (i = 0; i <= N; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1]
						+ K[i - 1][w - wt[i - 1]],
						K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[N][W];
}

int main()
{
    int N,W;
    scanf("%d %d", &N, &W);
    int wt[N], val[N];

    for(int i=0; i<N; i++)
    {
        scanf("%d", &wt[i]);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &val[i]);
    }
	printf("%d", knapSack(wt, val, N, W));
	return 0;
}
