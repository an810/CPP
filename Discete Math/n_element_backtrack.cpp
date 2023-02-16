#include<bits/stdc++.h>
using namespace std;

int n, x[100];
int mark[100];

void Input()
{
    cin >> n;
    for (int i=1; i<=n; i++) mark[i] = 0;
}

void Solution()
{
    for (int i=1; i<=n; i++) cout << x[i] << " ";
    cout << "\n";
}

void Try(int k)
{
    for(int v=1; v<=n; v++)
    {
        if (!mark[v])
        {
            x[k] = v;
            mark[v] = 1;
            if (k==n) Solution();
            else Try(k+1);
            mark[v] = 0;
        }  
    }
}

int main()
{
    Input();
    Try(1);
    return 0;
}
