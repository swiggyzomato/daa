#include<stdio.h>
#include <stdlib.h>
#include<math.h>

void addition(int **x, int **y, int **z, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            z[i][j]=x[i][j]+y[i][j];
        }
    }
}

void subtraction(int **x, int **y, int **z, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            z[i][j]=x[i][j]-y[i][j];
        }
    }
}

void split_matrix(int **A, int **a, int **b, int **c, int **d, int n)
{
    // a = (int**)malloc(n * sizeof(int *));
    // b = (int**)malloc(n * sizeof(int *));
    // c = (int**)malloc(n * sizeof(int *));
    // d = (int**)malloc(n * sizeof(int *));
    
    // for(int i=0; i<n; i++)
    // {
    //     a[i]= (int*)malloc(n * sizeof(int));
    //     b[i]= (int*)malloc(n * sizeof(int));
    //     c[i]= (int*)malloc(n * sizeof(int));
    //     d[i]= (int*)malloc(n * sizeof(int));
    // }

    for(int i=0; i<n/2; i++)
    {
        for(int j=0; j<n/2; j++)
        {
            a[i][j] = A[i][j];
            b[i][j] = A[i+n/2][j];
            c[i][j] = A[i][j+n/2];
            d[i][j] = A[i+n/2][j+n/2];
        }
    }
}

void merge_matrix(int **c11, int **c12, int **c21, int **c22, int **z, int n)
{
    for(int i=0; i<n/2; i++)
    {
        for(int j=0; j<n/2; j++)
        {
            z[i][j] = c11[i][j];
            z[i+(n/2)][j] = c12[i][j];
            z[i][j+(n/2)] = c21[i][j];
            z[i+(n/2)][j+(n/2)] = c22[i][j];
        }
    }
}

void strassen_multiplication(int **x, int **y, int **z, int n)
{
    if(n==1) {
        z[0][0] = x[0][0]*y[0][0];
        return;
    }
    
    int *a[n/2], *b[n/2], *c[n/2], *d[n/2], *e[n/2], *f[n/2], *g[n/2], *h[n/2], 
    *p1[n/2], *p2[n/2], *p3[n/2], *p4[n/2], *p5[n/2], *p6[n/2], *p7[n/2],
    *s1[n/2], *s2[n/2], *s3[n/2], *s4[n/2], *s5[n/2], *s6[n/2], *s7[n/2], *s8[n/2], *s9[n/2], *s10[n/2],
    *c11[n/2], *c12[n/2], *c21[n/2], *c22[n/2], *t1[n/2], *t2[n/2];

    for(int i=0; i<n/2; i++)
    {
        a[i]= (int*)malloc((n/2) * sizeof(int));
        b[i]= (int*)malloc((n/2) * sizeof(int));
        c[i]= (int*)malloc((n/2) * sizeof(int));
        d[i]= (int*)malloc((n/2) * sizeof(int));
        e[i]= (int*)malloc((n/2) * sizeof(int));
        f[i]= (int*)malloc((n/2) * sizeof(int));
        g[i]= (int*)malloc((n/2) * sizeof(int));
        h[i]= (int*)malloc((n/2) * sizeof(int));
        p1[i]= (int*)malloc((n/2) * sizeof(int));
        p2[i]= (int*)malloc((n/2) * sizeof(int));
        p3[i]= (int*)malloc((n/2) * sizeof(int));
        p4[i]= (int*)malloc((n/2) * sizeof(int));
        p5[i]= (int*)malloc((n/2) * sizeof(int));
        p6[i]= (int*)malloc((n/2) * sizeof(int));
        p7[i]= (int*)malloc((n/2) * sizeof(int));
        s1[i]= (int*)malloc((n/2) * sizeof(int));
        s2[i]= (int*)malloc((n/2) * sizeof(int));
        s3[i]= (int*)malloc((n/2) * sizeof(int));
        s4[i]= (int*)malloc((n/2) * sizeof(int));
        s5[i]= (int*)malloc((n/2) * sizeof(int));
        s6[i]= (int*)malloc((n/2) * sizeof(int));
        s7[i]= (int*)malloc((n/2) * sizeof(int));
        s8[i]= (int*)malloc((n/2) * sizeof(int));
        s9[i]= (int*)malloc((n/2) * sizeof(int));
        s10[i]= (int*)malloc((n/2) * sizeof(int));
        c11[i]= (int*)malloc((n/2) * sizeof(int));
        c12[i]= (int*)malloc((n/2) * sizeof(int));
        c21[i]= (int*)malloc((n/2) * sizeof(int));
        c22[i]= (int*)malloc((n/2) * sizeof(int));
        t1[i]= (int*)malloc((n/2) * sizeof(int));
        t2[i]= (int*)malloc((n/2) * sizeof(int));
    }

    split_matrix(x, a, b, c, d, n);
    split_matrix(y, e, f, g, h, n);

    // p1 = strassen(a, f - h) 
    // p2 = strassen(a + b, h)       
    // p3 = strassen(c + d, e)       
    // p4 = strassen(d, g - e)       
    // p5 = strassen(a + d, e + h)       
    // p6 = strassen(b - d, g + h) 
    // p7 = strassen(a - c, e + f)

    subtraction(f, h, s1, n/2);
    addition(a, b, s2, n/2);
    addition(c, d, s3, n/2);
    subtraction(g, e, s4, n/2);
    addition(a, d, s5, n/2);
    addition(e, h, s6, n/2);
    subtraction(b, d, s7, n/2);
    addition(g, h, s8, n/2);
    subtraction(a, c, s9, n/2);
    addition(e, f, s10, n/2);

    strassen_multiplication(a, s1, p1, n/2);
    strassen_multiplication(s2, h, p2, n/2);
    strassen_multiplication(s3, e, p3, n/2);
    strassen_multiplication(d, s4, p4, n/2);
    strassen_multiplication(s5, s6, p5, n/2);
    strassen_multiplication(s7, s8, p6, n/2);
    strassen_multiplication(s9, s10, p7, n/2);

    // c11 = p5 + p4 - p2 + p6 
    // c12 = p1 + p2          
    // c21 = p3 + p4           
    // c22 = p1 + p5 - p3 - p7

    addition(p5, p4, t1, n/2);
    subtraction(t1, p2, t2, n/2);
    addition(t2, p6, c11, n/2);
    addition(p1, p2, c12, n/2);
    addition(p3, p4, c21, n/2);
    addition(p1, p5, t1, n/2);
    subtraction(t1, p3, t2, n/2);
    subtraction(t2, p7, c22, n/2);

    merge_matrix(c11, c12, c21, c22, z, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int k = pow(2, ceil(log2(n)));

    int *x[k], *y[k], *z[k];
    for(int i=0; i<k; i++)
    {
        x[i]= (int*)malloc(n * sizeof(int));
        y[i]= (int*)malloc(n * sizeof(int));
        z[i]= (int*)malloc(n * sizeof(int));
    }

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
        {
            x[i][j] = 0;
            y[i][j] = 0;
            z[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &y[i][j]);
        }
    }

    strassen_multiplication(x, y, z, k);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }
    return 0;
}