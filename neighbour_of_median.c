#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int k)
{
    
    int pivot = arr[high];
    int i=low-1;

    for(int j=low; j<high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    if(k==i+1) {
        return i+1;
    }
    if(k<i+1) {
        return partition(arr, low, i, k);
    }
    
    return partition(arr, i+2, high, k);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    if(n%2==0)
    {
        printf("%d %d", arr[partition(arr, 0, n-1, n/2-2)], arr[partition(arr, 0, n-1, n/2+1)]);
    }
    else {
        printf("%d %d", arr[partition(arr, 0, n-1, n/2-1)], arr[partition(arr, 0, n-1, n/2+1)]);
    }

    return 0;
}