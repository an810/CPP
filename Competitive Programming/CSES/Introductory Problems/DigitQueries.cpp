// link: https://cses.fi/problemset/task/2431/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll digits = 1, start = 1, num_digits = 9;
        while (k > num_digits)
        {
            k -= num_digits;
            digits++;
            num_digits = 9 * pow(10, digits - 1) * digits;
            start *= 10;
        }

        ll target_num = start + (k - 1) / digits;
        string target_num_str = to_string(target_num);
        cout << target_num_str[(k - 1) % digits] << "\n";
    }
    return 0;
}