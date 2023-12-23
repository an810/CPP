#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000006

const ll INF = -1e18;

int n;
ll a[MAX];
ll S1[MAX], S0[MAX]; // S1 tonrg le, S0 tong chan
bool B1[MAX], B0[MAX]; // check tong chan hay tong le

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    // freopen("../test.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] % 2) {
        S1[1] = a[1]; 
        B1[1] = true; B0[1] = false;
    }
    else {        
        S0[1] = a[1];
        B1[1] = false; B0[1] = true;
    }
    for(int i = 2; i <= n; i++){
        if(a[i]%2 == 0){
            if(B0[i-1]){  
                if(S0[i-1] >0) S0[i] = S0[i-1] + a[i]; 
                else S0[i] = a[i]; B0[i] = true;  
            } 
            else {
                S0[i] = a[i]; 
                B0[i] = true;  
            }
            if(B1[i-1]){ 
                S1[i] = S1[i-1] + a[i]; 
                B1[i] = true;  
            }
            else{  
                B1[i] = false;  
            }                
        }else{
            if(B1[i-1]){
                S0[i] = S1[i-1] + a[i]; 
                B0[i] = true;  
            }
            else{   
                B0[i] = false;    
            }
            if(B0[i-1]){   
                if(S0[i-1] > 0) S1[i] = S0[i-1] + a[i]; 
                else S1[i] = a[i];  B1[i] = true;   
            }
            else{    
                S1[i] = a[i]; B1[i] = true;     
            }
        }
    }

    ll ans = INF;
    for (int i=1; i<=n; i++) 
        if (B0[i])
            ans = max(ans, S0[i]);
    cout << ans;
    return 0;
}