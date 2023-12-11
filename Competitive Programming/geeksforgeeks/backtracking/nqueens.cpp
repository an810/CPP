// link: https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 4

int ans[N][N];

void printSolution(int ans[N][N]) {
    cout << "----------------------------------\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (ans[i][j] == 1) cout << "Q ";
            else cout << "_ ";
        }
        cout<<endl;
    }
    cout << "----------------------------------\n";
}

int check(int x, int y, int ans[N][N]) {
    for (int i=0; i<N; i++)
        if (ans[i][y] == 1) return 0;  
    for (int i=x, j=y; i>=0 && j>=0; i--, j--) 
        if (ans[i][j] == 1) return 0;
    for (int i=x, j=y; i>=0 && j<N; i--, j++)
        if (ans[i][j] == 1) return 0;
    return 1;
}

void solve(int row, int ans[N][N]) {
    if (row == N) {
        printSolution(ans);
        return;
    }
    for (int i=0; i<N; i++) {
        if (check(row, i, ans)) {
            ans[row][i] = 1;
            solve(row+1, ans);
            ans[row][i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    solve(0, ans);
    return 0;
}