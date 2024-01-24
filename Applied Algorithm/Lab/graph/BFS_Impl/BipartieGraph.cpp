/*
    Cho một đồ thị vô hướng liên thông gồm n đỉnh (0<n<200). Các đỉnh được đánh số từ 0 đến n−1. 
    Và không tồn tại cạnh nối từ một đỉnh đến chính nó (đồ thị không có khuyên).
    Bạn hãy kiểm tra xem đồ thị có thể được tô bằng 2 màu hay không. Nghĩa là ta có thể gán màu (từ một bảng gồm 2
    màu) cho mỗi đỉnh của đồ thị theo cách sao cho không có 2 đỉnh nào kề cạnh nhau có cùng màu.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 210;

int n,l;
int color[maxN];
vector<int> g[maxN];

bool checkBipartieGraph() {
    fill_n(color, n+1, -1);

    queue<int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (color[v] == color[u]) return false;
            if (color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    while (cin >> n) {
        if (!n) return 0;

        cin >> l;
        while (l--) {
            int u, v;
            cin >> u >> v; 
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (!checkBipartieGraph()) cout << "NOT ";
        cout << "BICOLORABLE.\n";
        
        for (int i=0; i<n; i++) g[i].clear();
    }
    return 0;
}