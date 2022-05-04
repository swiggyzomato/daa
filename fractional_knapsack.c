#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int N;

void swap(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

void swapI(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(double arr[], int dl[], int start, int end)
{
    int pI = start + rand()%(end-start+1);
    swap(&arr[pI], &arr[end]);
    swapI(&dl[pI], &dl[end]);
    int pivot = arr[end];
    int i = start-1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j]>pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swapI(&dl[i], &dl[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    swapI(&dl[i+1], &dl[end]);
    return (i+1);
}

void QuickSort(double arr[], int dl[], int start, int end)
{
    if(start<=end)
    {
        int pIndex = Partition(arr, dl, start, end);

        QuickSort(arr, dl, start, pIndex-1);
        QuickSort(arr, dl, pIndex+1, end);
    }
}

int maxDeadline(int dl[]) {
    int mx=INT_MIN;
    for(int i=0;i<N;i++)
        mx=(dl[i]>mx)?dl[i]:mx;

    return mx;
}

double FractionalKnapsack(int profit[], int weight[], double pw[], int idx[], int M) {
    double ans=0;
    int m=M;

    for(int i=0; i<N; i++)
    {
        if(weight[idx[i]]<=m && m>0) {
            ans+=profit[idx[i]];
            m-=weight[idx[i]];
        }
        else {
            ans+=pw[i]*m;
            m-=m;
        }
    }
    return ans;
}

int main()
{
    int m;
    scanf("%d %d", &N, &m);
    int profit[N];
    int weight[N];
    double pw[N];
    int idx[N];

    for(int i=0;i<N;i++) { 
        scanf("%d", &profit[i]);
    }
    for(int i=0;i<N;i++) { 
        scanf("%d", &weight[i]);
    }
    for(int i=0;i<N;i++) { 
        pw[i]=profit[i]/weight[i];
        idx[i]=i;
    }
    

    QuickSort(pw, idx, 0, N-1);
    printf("%0.1f", FractionalKnapsack(profit, weight, pw, idx, m));
    
    return 0;
}