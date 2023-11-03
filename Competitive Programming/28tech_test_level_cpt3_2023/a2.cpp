// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/A2
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    if (n % k == 0) {
        cout << n/k;
    }else {
        cout << n/k + 1;
    }
    return 0;
}
 