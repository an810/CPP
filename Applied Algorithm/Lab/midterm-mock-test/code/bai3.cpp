/*
    Cho 1 dãy các số nguyên a1, a2,... an. CHo 2 số nguyên dương k và m. Tính giá 
    trị của Q là số cách chọn ra k phẩn tử từ dãy đã cho sao cho tổng của các phần
    tử được chọn bằng m
    1 <= n <= 20    1 <= k <= n/2    1 <= m <= 1000
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 20

int n, k, m;
int a[MAX+1];
int Q = 0;
set<vector<int>> s;
int visited[MAX+1] = {0};

void input() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solution() {
    int sum = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            sum += a[i];
            v.push_back(a[i]);
        } 
    }
    if (sum == m) s.insert(v);
}

void TRY(int x) {
    for (int i = 1; i <= n; i++) {
        if (!visited[a[i]]) {
            visited[a[i]] = 1;
            if (x == k) solution();
            else TRY(x + 1);
            visited[a[i]] = 0;
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    TRY(1);
    Q = s.size();
    cout << Q << endl;
    return 0;
}