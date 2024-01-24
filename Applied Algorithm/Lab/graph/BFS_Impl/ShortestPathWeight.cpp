/*
    Cho một đồ thị có hướng N đỉnh và M cạnh (1≤N,M≤105). Tìm số cạnh ít nhất cần phải đảo chiều để tồn tại đường đi từ đỉnh 1 cho đến đỉnh N. 
    Các đỉnh được đánh số từ 1 đến N. Đồ thị có thể có nhiều cạnh nối giữa một cặp đỉnh. Và có thể tồn tại cạnh nối từ một đỉnh đến chính nó (đồ thị có thể có khuyên).
    Gọi đồ thị ban đầu là G
    Ta sẽ thêm các cạnh ngược của mỗi cạnh ban đầu trong đồ thị G (nghĩa là, với mỗi cạnh u→v của đồ thị, ta sẽ thêm cạnh v→u vào). 
    Cho các cạnh ngược có trọng số bằng 1 và tất cả các cạnh ban đầu có trọng số bằng 0. Khi đó, ta sẽ có được đồ thị mới là đồ thị G′.
    Độ dài của đường đi ngắn nhất từ đỉnh 1 cho đến đỉnh N trong đồ thị G′ chính là đáp án của bài toán.

    - Chứng minh: Trong đồ thị G′, xét từng cạnh trên một đường đi từ 1 đến N. Nếu cạnh đó có trọng số là 0 thì đã tồn tại cạnh đó trên đồ thị G ban đầu, 
    còn nếu trọng số là 1 thì cạnh ngược lại của nó tồn tại trong đồ thị G. Khi đó ta sẽ phải đảo chiều cạnh đó. Nhận thấy sau khi xét toàn bộ các cạnh, ta sẽ thu được một đường đi từ 1 đến N, 
    và số cạnh ta phải đảo chiều chính là số cạnh 1 trong đường đi đó.
    Ta sử dụng kĩ thuật 0-1 BFS :
    - Nó có tên gọi như vậy vì kĩ thuật 0-1 BFS thường được sử dụng để tìm đường đi ngắn nhất trong đồ thị có trọng số 0 hoặc 1. 
    - Khi trọng số của các cạnh bằng 0 hoặc 1, thuật toán BFS thông thường sẽ trả ra kết quả sai, vì thuật toán BFS thông thường chỉ đúng trong đồ thị có trọng số của các cạnh bằng nhau.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int inf = 1e9;
const int maxN = 1e5+7;

int n, m;
int d[maxN];
vector<pair<int, int>> g[maxN];

void bfs(int s) {
    fill_n(d, n+1, inf);
    deque<int> q;
    q.push_back(s);
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if (u==n) return;
        for (auto edge : g[u]) {
            int v = edge.second;
            int w = edge.first;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (w) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    d[n] = -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({0, v});
        g[v].push_back({1, u});
    }
    bfs(1);
    cout << d[n];
    return 0;
}