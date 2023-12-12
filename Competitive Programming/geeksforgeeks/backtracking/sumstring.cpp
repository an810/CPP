// link: https://www.geeksforgeeks.org/check-given-string-sum-string/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s;

string sum_string(string s1, string s2) {
    string ans = "";
    int carry = 0;
    int i = s1.length()-1;
    int j = s2.length()-1;
    while(i>=0 && j>=0) {
        int sum = (s1[i]-'0') + (s2[j]-'0') + carry;
        ans += (sum%10 + '0');
        carry = sum/10;
        i--;j--;
    }
    while(i>=0) {
        int sum = (s1[i]-'0') + carry;
        ans += (sum%10 + '0');
        carry = sum/10;
        i--;
    }
    while(j>=0) {
        int sum = (s2[j]-'0') + carry;
        ans += (sum%10 + '0');
        carry = sum/10;
        j--;
    }
    if(carry) ans += (carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int checkSumStr(string s, int begin, int len1, int len2) {
    string s1 = s.substr(begin, len1);
    string s2 = s.substr(begin+len1, len2);
    string sum = sum_string(s1, s2);
    int len3 = sum.length();
    if(begin+len1+len2+len3 > s.length()) return 0;
    string s3 = s.substr(begin+len1+len2, len3);
    if(s3 == sum) {
        if(begin+len1+len2+len3 == s.length()) return 1;
        return checkSumStr(s, begin+len1, len2, len3);
    }
    return 0;
}

int isSumStr(string s) {
    int n = s.length();
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n-i; j++) {
            if(checkSumStr(s, 0, i, j)) return 1;
        }
    }
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    cout << isSumStr(s) << endl;
    return 0;
}