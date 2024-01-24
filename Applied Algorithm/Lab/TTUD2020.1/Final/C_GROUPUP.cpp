#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n, cnt = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        while(n > 1){
            if(n%2 == 1){
                a[n] = 0;
                n++;
            }
            n = n/2;
            for(int i = 0; i < n; i++){
                a[i] = a[2*i] + a[2*i+1];
            }
            cnt += *max_element(a, a + n);
        }
        cout << cnt <<endl;
    }
    return 0;
}