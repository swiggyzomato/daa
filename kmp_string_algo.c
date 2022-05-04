#include<stdio.h>

void prefix_suffix_pattern(char ptrn[], int count[], int m)
{
    int j=0, i=1;
    count[0]=0;
    

    while(i<m)
    {
        if(ptrn[i]!=ptrn[j]) {
            i++;
        }
        else
        {
            count[i]=j+1;
            i++;
            j++;
        }
    }
}

void KMPSearch(char str[], char ptrn[], int count[], int n, int m)
{
    prefix_suffix_pattern(ptrn, count, m);
    int j=0, i=0;
    while(i<n)
    {
        
        if(str[i]==ptrn[j])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            printf("Pattern found at index: %d", i-j);
            j=count[j-1];
        }
        else if(i<n && ptrn[j]!=str[i])
        {
            if(j!=0) {
                j=count[j-1];
            }
            else
                i++;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char str[n], ptrn[m];
    int count[m];

    scanf("%s %s", str, ptrn);

    for(int i=0; i<m; i++)
        count[i]=0;

    KMPSearch(str, ptrn, count, n, m);

    // prefix_suffix_pattern(ptrn, count, m);
    return 0;
}