#include <bits/stdc++.h> 
using namespace std;

int n;

int main() 
{ 
    cin >> n;
    int ans = 0;
    while (ans < 100) {
        ans += n;
    }
    cout << ans << " ";
    while (ans + n < 999) {
        ans += n;
        cout << ans << " ";
    }
    return 0;
}