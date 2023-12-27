#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 20

int n, m;
int x[MAX], A[MAX], t[MAX];
int ans = 0;
int sum = 0;

void solution()
{
    ans++;
}

void Try(int k)
{
    for(int v = 1; v <= (m-sum - (t[n]-t[k])/A[k]); v++)
    {
        x[k] = v;
        sum += x[k] * A[k];
        if(k == n)
        {
            if(sum == m)
                solution();
        }
        else
            Try(k + 1);
        sum -= x[k] * A[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    t[0] = A[0];
    for (int i = 1; i < n; i++)
        t[i] = t[i - 1] + A[i];
    Try(1);
    cout << ans;
    return 0;
}