// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/I

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    vector<string> users;
    unordered_map<string, int> database;
    for (int i=0; i<t; i++) {
        string s; cin >> s;
        users.push_back(s);
    }
    for (int i=0; i<t; i++) {
        database[users[i]]++;
        if (database[users[i]] == 1) 
            cout << "OK\n";
        else cout << users[i] + to_string(database[users[i]] -1) << "\n"; 
    }
    return 0;
}