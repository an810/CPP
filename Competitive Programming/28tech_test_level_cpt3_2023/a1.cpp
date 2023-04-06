// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/A1
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
    string ans ="";
    int carry = 0;
    long i = a.length()-1, j = b.length()-1;
    while (i>=0 && j>=0) {
        int temp = (a[i] - '0') + (b[j] - '0') + carry;
        if (temp >= 10) {
            ans += (temp - 10) + '0';
            carry = 1;
        } else {
            ans += temp + '0';
            carry = 0;
        }
        i--;j--;
    }
    while (i>=0) {
        int temp = (a[i] - '0') + carry;
        if (temp >= 10) {
            ans += (temp - 10) + '0';
            carry = 1;
        } else {
            ans += temp + '0';
            carry = 0;
        }
        i--;
    }
    while (i>=0 && j>=0) {
        int temp = (b[j] - '0') + carry;
        if (temp >= 10) {
            ans += (temp - 10) + '0';
            carry = 1;
        } else {
            ans += temp + '0';
            carry = 0;
        }
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
} 