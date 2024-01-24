#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge
{
    int u, v;
    int weight;

    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        weight = _w;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<edge> Adj[5];
    Adj[1].push_back(edge(1, 2, 9));
    Adj[1].push_back(edge(1, 3, -7));
    Adj[2].push_back(edge(2, 1, 9));
    Adj[2].push_back(edge(2, 3, 0));
    Adj[3].push_back(edge(3, 1, -7));
    Adj[3].push_back(edge(3, 2, 0));
    Adj[3].push_back(edge(3, 4, 5.1));
    Adj[4].push_back(edge(4, 3, 5.1));

    return 0;
}