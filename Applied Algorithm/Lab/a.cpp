#include <bits/stdc++.h>
using namespace std;

int n,c,res=0;
int a[30];
int dp[100000];

int main() {
    cin>>n>>c;
    for (int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);

    dp[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=c-a[i];j>=0;j--) {
            if (dp[j]) dp[j+a[i]]=1;  
        }
            
    }

    for (int i=0;i<=c;i++)
        if (dp[i]) res=max(res,i);

    cout<<res<<endl;
}