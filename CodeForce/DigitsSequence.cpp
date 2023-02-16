//  Link: https://codeforces.com/contest/1177/problem/A
#include<bits/stdc++.h>
using namespace std;

string digits;
int len = 10000;

string toString(int n) {
    string s; 
    while (n) {
        int temp = n%10;
        s += temp + '0';
        n/=10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() { 
    for (int i=0; i<=len; i++) {
        digits += toString(i);
    }
    int n; 
    cin >> n; 
    cout << digits[n-1];
}