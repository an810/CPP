#include <bits/stdc++.h> 
// Longest increasing subsequence


using namespace std;

const int MAX = 10001;
int n;
int a[MAX];
int iMem[MAX];

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int solve(int r)
{
    if (r == 1) return 1;

    if (iMem[r] != -1) return iMem[r];

    int res = 1;
    for (int i = 1; i < r; i++)
    {
        if (a[r] > a[i])
            res = max(res, 1 + solve(i));
    }
    iMem[r] = res;
    return res;
}

int main(void)
{
    memset(iMem,-1,sizeof(iMem));
    freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve(n);
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,iMem[i]);
    }
    cout << ans << endl;
}
