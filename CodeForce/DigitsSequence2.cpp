// Link: https://codeforces.com/contest/1177/problem/B
#include<bits/stdc++.h>
using namespace std;    

int main() {
    long long k;
    cin >> k;

    long long digits = 1, start = 1, num_digits = 9;
    while (k > num_digits) {
        k -= num_digits;
        digits++;
        num_digits = 9 * pow(10, digits - 1) * digits;
        start *= 10;
    }

    long long target_num = start + (k - 1) / digits;
    string target_num_str = to_string(target_num);
    cout << target_num_str[(k - 1) % digits] << endl;

    return 0;
}
