// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B4
#include<bits/stdc++.h>
using namespace std;

int n, t, l, r;
int a[1000000];
long long res[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        res[i] = res[i-1] + a[i];
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &l, &r);
        printf("%lld\n", res[r] - res[l-1]);
    }

    return 0;
}
