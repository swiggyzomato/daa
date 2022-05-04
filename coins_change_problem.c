#include<stdio.h>
#include<limits.h>
#include <string.h>

int min(int a, int b) {
    return (a<b)?a:b;
}

int minCoinsDP(int arr[], int N, int V) 
{
    int dp[V+1];
    dp[0]=0;

    for(int i=1; i<=V; i++)
    {
        int mn=INT_MAX;
        for(int j=0;j<N;j++)
        {
            if(arr[j]<=i)
            {
                mn=min(mn, dp[i-arr[j]]+1);
            }
        }
        dp[i]=mn;
    }
    if(dp[V]==INT_MAX)
        return 0;

    return dp[V];
}

int minCoins(int arr[], int N, int V)
{
    if(V==0)
        return 0;

    int mn=INT_MAX;
    
    for(int i=0; i<N; i++) {
        if(arr[i]<=V) {
            mn=min(mn, 1+minCoins(arr, N, V-arr[i]));
        }
    }

    if(mn==INT_MAX)
        return 0;

    return mn;
}

int main()
{
    int n,v;
    scanf("%d %d", &n, &v);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d", minCoinsDP(arr,n,v));

    return 0;
}