#include <bits/stdc++.h> 
#define N 1000006
using namespace std;
int n; 
int a[N];
int main() 
{ 
    cin >> n;
    long long sum = 0;
    for (int i=0; i<n; i++)  {
        cin >> a[i];
        sum += a[i];
    }
    cout << sum;
    return 0;
}