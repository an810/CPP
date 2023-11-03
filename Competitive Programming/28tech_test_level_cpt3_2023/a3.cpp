//link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/A3
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int year;
    cin >> year;
    if (year % 4 ==0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                cout << "Yes";
            } else cout << "No";
        } else cout << "Yes";
    } else cout << "No";
    return 0;
}