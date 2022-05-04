#include<stdio.h>
#include<math.h>

void MergeCalculate(int arr[], int l, int mid, int r, int *mn, int *mx)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];
    for(int i=0; i<n1; i++)
    {
        a[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++)
    {
        b[j] = arr[mid + 1 + j];
    }

    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    *mn=arr[l+1];
    *mx=arr[r-1];
}

void second_Smallest_Largest(int arr[], int l, int h, int *mn, int *mx)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        second_Smallest_Largest(arr, l, mid, mn, mx);
        second_Smallest_Largest(arr, mid+1, h, mn, mx);

        MergeCalculate(arr, l, mid, h, mn, mx);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int mn, mx;

    second_Smallest_Largest(arr, 0, n-1, &mn, &mx);

    printf("Second Smallest: %d, Second Largest: %d", mn, mx);
    return 0;
}