#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mxN 20004

int n, m, M;
int a[mxN];
ll s[mxN];
int Q = 0;

void input() {
    // freopen("../../test.txt", "r", stdin);
    cin >> n >> m >> M;
    s[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}

int searchMin(int begin, int target) {
    int res = -1; 
    int l = begin, r = n;
    while (l <= r) {
        int mid = (l + r )/2;
        if (s[mid]-s[begin-1] >= target) {
            res = mid;
            r = mid - 1;
            continue;
        } 
        if (s[mid] - s[begin-1] < target) {
            l = mid + 1;
            continue;
        }
    }
    return res;
}

int searchMax(int begin, int target) {
    int res = -1; 
    int l = begin, r = n;
    while (l <= r) {
        int mid = (l + r )/2;
        if (s[mid]-s[begin-1] <=  target) {
            res = mid;
            l = mid + 1;
            continue;
        } 
        if (s[mid] - s[begin-1] > target) {
            r = mid - 1;
            continue;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    for (int i=1; i<=n; i++) {
        int l = searchMin(i, m);
        int r = searchMax(i, M);
        if (l != -1 && r != -1) {
            Q += r - l + 1;
        }
    }
    cout << Q;
    return 0;
}