// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B1
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000010];

long long totalGap(int left, int right)
{
    long long total_gap = 0;
    for (int i = left; i <= right; i++)
        total_gap += (a[right] - a[i]);
    return total_gap;
}

int bsearch(int left, int right)
{
    int l = left, r = right, m, res = left;
    while (l <= r)
    {
        m = (l + r) / 2;
        long long total_gap = totalGap(left, m);
        if (total_gap == k)
            return m;
        else if (total_gap < k)
        {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    int index = bsearch(n / 2 + 1, n);
    long long total_gap = totalGap(n / 2 + 1, index);
    int res = a[index] + ((k - total_gap) / (index - n / 2));

    cout << res << endl;
}