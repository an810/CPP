// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B2
#include <bits/stdc++.h>
using namespace std;

int n;
int x[11], mark[11];

template <typename T> inline void writep(T x)
{
    if (x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x)
{
    if (x<0)
    {
        putchar('-');
        x=-x;
    }
    writep(x);
}

void printSolution()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d",x[i]);
    }
    putchar('\n');
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (mark[v] == 0)
        {
            mark[v] = 1;
            x[k] = v;
            if (k == n)
                printSolution();
            else
                Try(k + 1);
            mark[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        mark[i] = 0;
    }
    Try(1);
    return 0;
}
