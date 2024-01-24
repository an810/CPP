#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    char *str;
    cin >> str;
    int h, m, s;
    sscanf(str, "%d:%d:%d", &h, &m, &s);
    if (str.length() != 8) 
        cout << "INCORRECT\n";
    return 0;
}