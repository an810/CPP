#include<bits/stdc++.h>

using namespace std;

int n;
int c[100][100];
int x[100];
int mark[100];
int sum = 0;

int ans = INT_MAX;

void Input()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> c[i][j];
        }
    }
}

void Try(int k)
{
    for (int v=2; v <= n; v++)
    {
        if (!mark[v])
        {
            x[k]=v;
            mark[v]=1;
            sum += c[x[k-1]][x[k]];
            if (k==n) 
            {
                int temp = sum + c[x[k]][x[1]];
                ans = min(temp, ans);
            } else Try(k+1);
            mark[v]=0;
            sum -= c[x[k-1]][x[k]];
        }
    }
}

int main()
{
    Input();
    x[1] = 1;
    Try(2);
    cout << ans;
    return 0;
}