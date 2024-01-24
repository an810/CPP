#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 20

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    char s[N];
    cin >> s;
    int year, month, date;
    // if (s.length() != 10) {
    //     cout << "INCORRECT\n";
    //     return 0;   
    // }
    sscanf(s, "%d-%d-%d", &year, &date, &month);
    cout << year << " " << month << " " << date;
    return 0;
}