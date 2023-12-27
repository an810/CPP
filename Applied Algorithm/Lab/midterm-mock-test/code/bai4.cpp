/*
    Cho một dãy gồm các số nguyên dương a1, a2,..., an. Tìm tập con của dãy đã cho 
    sao cho tổng các phần tử trong tập con này là lớn nhất và trong tập con này 
    không chứa 3 phần tử nào liên tiếp nhau trong dãy đã cho.
    1 <= n <= 10^5    1 <= ai <= 10^3
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100000

int n;
int a[MAX];
int sum = 0;
int dp[MAX];


int main()
{
    freopen("../test-case/bai4.txt", "r", stdin);
    // freopen("", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = max({dp[i-1], dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]});
    }
    cout<< dp[n];
    return 0;
}