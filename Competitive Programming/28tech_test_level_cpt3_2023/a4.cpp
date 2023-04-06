// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/A4
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <=sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <=n; j+=i) {
                isPrime[j] = false;
            }
        }
        
    }
    for (int i = 2; i<=n; i++) {
        if(isPrime[i]) {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}