#include<stdio.h>
#include<math.h>

int max(int a, int b)
{
    return (a>b)?a:b;
}

int min(int a, int b) {
    return (a<b)?a:b;
}

double median_of_two(int arr1[], int arr2[], int l1, int r1, int l2, int r2)
{
    if(r1-l1+1==2 && r2-l2+1==2)
    {
        return (max(arr1[l1], arr2[l2]) + min(arr1[r1], arr2[r2]))/2.0;
    }

    double m1, m2;
    if((l1+r1)%2==0)
    {
        m1=arr1[(l1+r1)/2];
    }
    else
    {
        m1=(arr1[(l1+r1)/2] + arr1[(l1+r1)/2 + 1])/2.0;
    }

    if((l2+r2)%2==0)
    {
        m2=arr2[(l2+r2)/2];
    }
    else
    {
        m2=(arr2[(l2+r2)/2] + arr1[(l2+r2)/2 + 1])/2.0;
    }

    int p1=(l1+r1)/2, p2=(l2+r2)/2;

    if(m1==m2)
    {
        return m1;
    }

    if(m1>m2)
    {
        return median_of_two(arr1, arr2, l1, p1, p2, r2);
    }
    return median_of_two(arr1, arr2, p1, r1, l2, p2);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr1[n], arr2[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr1[i]);

    for(int i=0; i<n; i++)
        scanf("%d", &arr2[i]);

    printf("%f", median_of_two(arr1, arr2, 0, n-1, 0, n-1));

    return 0;
}