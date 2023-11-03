// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t) {
        int n; cin >> n;
        vector<string> words;
        unordered_map<string, bool> words_map;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            words.push_back(s);
            words_map[s] = true;
        }
        for (int i=0; i<n; i++) {
            int len = words[i].length();
            int flag = 0;
            for (int j=1; j<len; j++) {
                string prefix = words[i].substr(0, j);
                string suffix = words[i].substr(j, len-j);
                if (words_map[prefix] && words_map[suffix]) {
                    flag = 1; break;
                }
            }
            if (flag) cout << "1";
            else cout << "0";    
        }
        cout << "\n";
        t--;
    }
    return 0;
}