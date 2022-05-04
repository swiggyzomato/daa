#include<stdio.h>

int bitonic_search(int arr[], int l, int r) 
{
    if(l==r) 
        return arr[l];

    int mid = (l+r)/2;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
    {
        return mid;
    }
    else if(arr[mid]<arr[mid-1])
    {
        return bitonic_search(arr, l, mid-1);
    }
    else if(arr[mid]<arr[mid+1])
    {
        return bitonic_search(arr, mid+1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Index: %d", bitonic_search(arr, 0, n-1));

    return 0;
}