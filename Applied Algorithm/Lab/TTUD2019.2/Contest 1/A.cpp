#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    string a, b, sum = "";
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len1 = a.length(), len2 = b.length();
    int len = min(len1, len2);
    int carry = 0;
    for (int i=0; i<len; i++) {
        int num1 = a[i] -'0';
        int num2 = b[i] - '0';
        sum += (num1 + num2 + carry) % 10 + '0';
        carry = (num1 + num2 + carry) / 10;
    }
    for (int i=len; i<len1; i++) {
        int num = a[i] -'0';
        sum += (num + carry) % 10 + '0';
        carry = (num + carry) / 10;
    }
    for (int i=len; i<len2; i++) {
        int num = b[i] -'0';
        sum += (num + carry) % 10 + '0';
        carry = (num + carry) / 10;
    }
    if (carry) sum += carry + '0';
    reverse(sum.begin(), sum.end());
    cout << sum;
    return 0;
}