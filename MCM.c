#include<stdio.h>
#include<limits.h>
#include<string.h>

int min(int a, int b)
{
    return (a>b)?b:a;
}

int dp[1001][1001];

int MCM(int arr[], int i, int j)
{
    if(i>=j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=INT_MAX;
    for(int k=i; k<j; k++){
        dp[i][j]=min(dp[i][j], MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j]);
    }

    return dp[i][j];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("%d", MCM(arr, 1, n-1));

    return 0;
}