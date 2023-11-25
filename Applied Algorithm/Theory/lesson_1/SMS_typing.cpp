#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    string keys[12] = {"", "abc", "def",
                    "ghi", "jkl", "mno",
                    "pqrs", "tuv", "wxyz",
                    "", " ", ""};
    int t; cin >> t;
    while (t--) {
        fflush(stdin);
        string line ;
        getline(cin, line);
        int cnt = 0;
        for ( int i = 0; i < line . size (); i ++) {
            int cur = 0;
            for ( int j = 0; j < 12; j ++) {
                for ( int k = 0; k < keys [ j ]. size (); k ++) {
                    if ( line [ i ] == keys [ j ][ k ]) {
                        cur = k + 1;
                    }
                }
            }
            cnt += cur ;
        }
        cout << cnt << "\n";
    }
    return 0;
}

