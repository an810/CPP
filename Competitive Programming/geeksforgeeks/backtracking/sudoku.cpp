// link: https://www.geeksforgeeks.org/sudoku-backtracking-7/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int ip[9][9];
int ans[9][9];
int markSquare[3][3][10];
int markRow[9][10];
int markCol[9][10];

void input() {
    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++) 
            cin >> ip[i][j];
}

void init() {
    for (int v=1; v<=9; v++) {
        for (int i=0; i<9; i++) {
            markCol[i][v] = 0;
            markRow[i][v] = 0;
        }
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                markSquare[i][j][v] = 0;
    }
}

void printSolution() {
    cout << "----------------------------------\n";
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "----------------------------------\n";
}

int check(int x, int y, int val) {
    if (markRow[x][val] == 1) return 0;
    if (markCol[y][val] == 1) return 0;
    if (markSquare[x/3][y/3][val] == 1) return 0;
    return 1;
}

void solve(int x, int y) {
    for (int v = (ip[x][y] > 0 ? ip[x][y] : 1); v <= (ip[x][y] > 0 ? ip[x][y] : 9); v++) {
        if (check(x,y,v)) {
            ans[x][y] = v;
            markRow[x][v] = 1;
            markCol[y][v] = 1;
            markSquare[x/3][y/3][v] = 1;
            if (x == 8  && y == 8) {
                printSolution();
                return;
            } else {
                if (y == 8) solve(x+1, 0);
                else solve(x, y+1);
            }
            markSquare[x/3][y/3][v] = 0;
            markRow[x][v] = 0;
            markCol[y][v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    input();
    init();
    solve(0, 0);
    return 0;
}