#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    int count=0;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i=1; i<n-1; i++)
    {
        if (a[i]>a[i-1] && a[i]>a[i+1]) count++;
    }
    printf("%d",count);
    return 0;
}