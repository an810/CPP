#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Sau qua trinh phan tich cay tai dinh u ma low[u]=num[u] thi ta tim duoc mot thanh phan cay lien thong manh theo qua trinh duyet cay tu u

vector<int> adj[10001];
vector<int> low(10001), num(10001, -1);
vector<bool> connect(10001, false);
int curnum = 0;

stack<int> iComp;

void SCC(int u) {
    iComp.push(u);
    connect[u] = true;
    low[u] = num[u] = ++curnum;

    for (int i=0; i< adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            SCC(v);
            low[u] = min(low[u], low[v]);
        } else if (connect[v]) {
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u]) {
        cout << "TPLT: ";
        while (true) {
            int cur = iComp.top();
            iComp.pop();
            connect[cur] = false;
            cout << cur << " "; 
            if (cur == u) break;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    for (int i =0; i<n; i++) {
        if (num[i] == -1)
            SCC(i);
    }
    return 0;
}