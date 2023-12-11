
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define ll long long

string bigsum(string a, string b) {
    string res = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len_a = a.length(), len_b = b.length();
    int len = min(len_a, len_b);
    int temp = 0, sum;
    for (int i = 0; i < len; i++) {
        int num1 = a[i] -'0';
        int num2 = b[i] - '0';
        sum = num1 + num2;
        res += (sum + temp) % 10 + '0';
        temp = (sum + temp) / 10;
    }
    for (int i = len; i < len_a; i++) {
        int num1 = a[i] - '0';
        res += (num1 + temp) % 10 + '0';
        temp = (num1 + temp) / 10;
    }
    for (int i = len; i < len_b; i++) {
        int num2 = b[i] - '0';
        res += (num2 + temp) % 10  + '0';
        temp = (num2 + temp) / 10;
    }
    if (temp) res += temp +'0';
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    string a,b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    string res = bigsum(a,b);
    cout << res;
    return 0;
}