// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B3
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignore newline character after t
    
    for (int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string in;
        int cnt = 0;
        while(ss >> in) cnt++;
        cout << cnt << '\n';
    }
    
    return 0;
}
