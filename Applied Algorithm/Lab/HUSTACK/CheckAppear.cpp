#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005

int n;
int a[N];
unordered_map<int, int> dict;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i< n; i++) {
        if (dict[a[i]] == 0) {
            dict[a[i]]++;
            cout << "0\n";
        } else cout << "1\n";
    }

    return 0;
}