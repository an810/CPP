// N queens có sẵn con hậu trên bàn cờ

#include<stdio.h>
#define N 100

int n;
int x[N];
int K;
int a[N];
int ans;

void Input()
{
    scanf("%d", &n);
    scanf("%d", &K);
    for(int i=0; i<n;i++) a[i] =0;
    for (int k=1; k<=K; k++)
    {
        int r,c;
        scanf("%d %d", &r, &c);
        a[c]=r;
    }
}

int check(int v, int k)
{
    for (int i=1; i<=k-1; i++)
    {
        if (x[i]==v) return 0;
        if (x[i]+i==v+k) return 0;
        if (x[i]-i==v-k) return 0;
    }
    return 1;
}

void solution()
{
    //for (int i=1;i<=n;i++) printf("%d ", x[i]); printf("\n");
    ans ++;
}

void Try(int k)
{
    for (int v=(a[k]>0 ? a[k] : 1); v<= (a[k]>0 ? a[k] : n); v++)
    {
        if (check(v,k))
        {
            x[k] = v;
            if (k==n) solution();
            else Try(k+1);
        }
    }
}

int main()
{   
    Input();
    ans =0;
    Try(1);
    printf("%d", ans);
    return 0;
}
