#include<bits/stdc++.h>
using namespace std;

int m,n;
int x[100];

void Input()
{
    cin >> n >> m;
}

void Solution()
{
    for (int i=1; i<=m; i++) cout << x[i] << " ";
    cout << "\n";
}

void Try(int k)
{
    for (int v=x[k-1]+1; v<=n-m+k; v++)
    {
        x[k] = v;
        if (k==m) Solution();
        else Try(k+1);
    }
}

int main()
{
    Input();
    Try(1);
    return 0;
}