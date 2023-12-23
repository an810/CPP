#include<bits/stdc++.h>
using namespace std;

int n,m;
int x[10001], y[10001];
int mem[10001][10001];

int lcs(int i, int j){
    int res = -1;
    if(mem[i][j] != -1) return mem[i][j];
    if(x[i] == y[j]){
        res = max(res, lcs(i-1, j-1) + 1);
    }
    else{
        res = max(lcs(i-1, j), lcs(i, j-1));
    }
    mem[i][j] = res;
    return res;
}

int main(){
    cin >> n >>m;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int j = 1; j <= m; j++){
        cin >> y[j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mem[i][j] = -1;
        }
    }
    cout << lcs(n,m);
    return 0;
}