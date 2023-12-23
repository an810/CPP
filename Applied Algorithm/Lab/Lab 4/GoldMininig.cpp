#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100000

int n, l1, l2;  
int a[MAX+1];
int dp[MAX+1];
deque<int> q;
int qmax = -1;

void input() {
    // freopen("../test.txt", "r", stdin);
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n > l2) {
        for (int i=l1; i<=l2; i++) {
                
        }

    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (i <= l1) dp[i] = a[i];
        else if (i <= l2) {
            int tmax = -1;
            for (int j=1; j<=i-l1; j++) 
                tmax = max(tmax, dp[j]);
            for (int j=i-l1+1; j<i; j++)
                dp[i] = max(a[i] + tmax, dp[j]);
        }
        else {
            int tmax = -1;
            for (int j=i-l2; j<=i-l1; j++)
                tmax = max(tmax, dp[j]);
            for (int j=i-l1+1; j<i; j++)
                dp[i] = max(a[i] + tmax, dp[j]);
        } 
    }
    int res = -1;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    solve();
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

#define N 1000006
int n, l, r;
int a[N];

int maxProduct(int arr[N], int n, int l, int r)
{
    int dp[N], res = 0;
    deque<int> dq;
    for (int i = 0; i < n; ++i)
    {
        int maxPrev = 0;
        if (i >= l)
        {
            if (!dq.empty() && dq.front() + r < i) dq.pop_front();
            while (!dq.empty() && dp[dq.back()] <= dp[i - l])
            {
                dq.pop_back();
            }
            if (dq.empty())
                maxPrev = dp[i - l];
            else
                maxPrev = dp[dq.front()];
            dq.push_back(i - l);
        }
        dp[i] = maxPrev + arr[i];
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    cin >> n >> l >> r;
    for (int i=0; i<n; i++) cin >> a[i];
    cout << maxProduct(a,n,l,r);
    return 0;
}
*/