// link: https://www.geeksforgeeks.org/the-knights-tour-problem/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 8

int ans[N][N];
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };  
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void init() {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            ans[i][j] = -1;
    ans[0][0] = 0;
}

int check(int x, int y, int ans[N][N]) {
    return (x>=0 && x<N && y>=0 && y<N && ans[x][y] == -1);
}

void printSolution(int ans[N][N]) {
    cout << "----------------------------------\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "----------------------------------\n";
}

void solve(int x, int y, int move, int xMove[], int yMove[]) {
    if (move == N*N) {
        printSolution(ans);
        return;
    }
    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if (check(next_x, next_y, ans)) {
            ans[next_x][next_y] = move;
            solve(next_x, next_y, move + 1, xMove, yMove);
            ans[next_x][next_y] = -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    init();
    solve(0, 0, 1, xMove, yMove);
    return 0;
}