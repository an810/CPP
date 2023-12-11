/*
    Cho một dãy gồm các số nguyên a1, a2, ..., am. Một dãy con k-phần tử của dãy 
    đã cho là một dãy gòm k phần tử liên tiếp của dãy đã cho. Trọng số của dãy 
    con k-phần tử là tổng của các phần tử trong dãy con này. Cho các số nguyên 
    dương k, A và B. Tính Q là số lượng dãy con k-phần tử sao cho trọng số mỗi dãy
    con này đều lớn hơn hoặc bằng A và nhỏ hơn hoặc bằng B (A ≤ q ≤ B).
    1 ≤ n ≤ 10^5    1 ≤ k ≤ n/2    1 ≤ A ≤ B ≤ 10^6
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 100000

int n;
int a[MAX];
int k, A, B;
int Q = 0;

void input(){
    cin >> n >> k >> A >> B;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int solve() {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    for (int i = 0; i < n - k; i++) {
        if (sum >= A && sum <= B) Q+=1;
        sum -= a[i];
        sum += a[i + k];
    }
    return Q;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    cout << solve();
    return 0;
}