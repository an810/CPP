//  Link: https://codeforces.com/contest/1294/problem/C
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long n;
    long long num; 
    int count;
    while (t) {
        cin >> n;
        num = n;
        count = 0;
        vector<long long> a;
        for (int i=2; i<sqrt(num); i++) {
            if (n%i == 0) {
                count++;
                n /= i;
                a.push_back(i);
            }
            if (count == 2) {
                a.push_back(n);
                break;
            }
        }
        if (count < 2) {
            cout << "NO\n";
        } else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << a[0] << " " << a[1] << " " << a[2] << "\n";
        }
        t--;
    }
}