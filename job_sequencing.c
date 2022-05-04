#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int N;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[], int dl[], int start, int end)
{
    int pI = start + rand()%(end-start+1);
    swap(&arr[pI], &arr[end]);
    swap(&dl[pI], &dl[end]);
    int pivot = arr[end];
    int i = start-1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j]>pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            swap(&dl[i], &dl[j]);
        }
    }
    swap(&arr[i+1], &arr[end]);
    swap(&dl[i+1], &dl[end]);
    return (i+1);
}

void QuickSort(int arr[], int dl[], int start, int end)
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

int JobSeqWithDeadlines(int arr[], int dl[]) {
    int len=maxDeadline(dl);
    int jobSlot[len];
    memset(jobSlot, 0, sizeof(jobSlot));

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<dl[i]; j++)
        {
            if(jobSlot[j]==0) {
                jobSlot[j]=arr[i];
                break;
            }
        }
    }

    int sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=jobSlot[i];
        
    }
    return sum;
}

int main()
{
    scanf("%d", &N);
    int arr[N];
    int dl[N];

    for(int i=0;i<N;i++) { 
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<N;i++) { 
        scanf("%d", &dl[i]);
    }

    QuickSort(arr, dl, 0, N-1);
    printf("%d", JobSeqWithDeadlines(arr,dl));
    
    return 0;

}