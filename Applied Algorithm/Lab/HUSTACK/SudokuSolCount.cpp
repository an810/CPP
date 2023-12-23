#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a[10][10], ans[10][10];
int markCol[9][10], markRow[9][10], markSquare[3][3][10];
int Q;

void input() {
    for (int i=0; i<9; i++) 
        for(int j=0; j<9; j++)
            cin >> a[i][j];
    for (int i=0; i<9; i++)
        for (int j=1; j<=9; j++) 
            markCol[i][j] = markRow[i][j] = 0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            for (int v=1; v<=9; v++)
                markSquare[i][j][v] = 0;
}

void solution() {
    Q++;
}

int check(int x, int y, int v) {
    if (markRow[x][v]) return 0;
    if (markCol[y][v]) return 0;
    if (markSquare[x/3][y/3][v]) return 0;
    return 1;
}

void solve(int x, int y) {
    for (int v = (a[x][y] > 0 ? a[x][y] : 1); v <= (a[x][y] > 0 ? a[x][y] : 9); v++) {
        if (check(x,y,v)) {
            ans[x][y] = v;
            markRow[x][v] = 1;
            markCol[y][v] = 1;
            markSquare[x/3][y/3][v] = 1;
            if (x==8 && y==8) {
                solution(); 
            } else {
                if (x==8) solve(0, y+1);
                else solve(x+1, y);
            }
            markRow[x][v] = 0;
            markCol[y][v] = 0;
            markSquare[x/3][y/3][v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    solve(0,0);
    cout << Q;
    return 0;
}