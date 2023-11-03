// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B5
#include<bits/stdc++.h>
using namespace std;
#define N 100
int main()
{
    int n;
    int a[N][N];
    cin >> n;
    int val = 1, round = 0, row = n - 1, col = n - 1;
    while (round <= n/2) 
    {
        for (int i = round; i <= col; i++) a[round][i] = val++;
        for (int i = round + 1; i <= row; i++) a[i][col] = val++;
        for (int i = col - 1; i >= round; i--) a[row][i] = val++;
        for (int i = row - 1; i > round; i--) a[i][round] = val++; 
        round++; row--; col--;
    } 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}