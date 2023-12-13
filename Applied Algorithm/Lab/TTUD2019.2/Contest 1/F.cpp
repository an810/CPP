#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if (s.length() > 10)
            cout << s[0] << s.length()-2 << s[s.length()-1] <<'\n';
        else cout << s << '\n';
    }
    return 0;
}