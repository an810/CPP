#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    int u, v, weight;
    edge(int _u, int _v, int _w) {
        u =_u;
        v = _v;
        weight = _w;
    }
};

int dist[1001][1001];
int weight[1001][1001];
void FloydWarshall(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j] = i == j ? 0 : weight[i][j];
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
}

int main()
{
    
    
    return 0;
}