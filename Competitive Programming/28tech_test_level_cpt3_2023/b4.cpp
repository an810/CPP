// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B4
#include<bits/stdc++.h>
using namespace std;

int n, t, l, r;
int a[1000010];
long long res[1000010];

template <typename T> inline void read(T &x)
{
    char c;
    bool nega=0;
    while ((!isdigit(c=getchar())) && (c!='-'));
    if (c=='-')
    {
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
} 
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
template <typename T> inline void writeln(T x)
{
    write(x);
    putchar('\n');
}

int main()
{
    read(n);
    for (int i=1; i<=n; i++)
    {
        read(a[i]);
        res[i] = res[i-1] + a[i];
    }
    read(t);
    while (t--)
    {
        read(l);read(r);
        long long ans = res[r] - res[l-1];
        writeln(ans);
    }

    return 0;
}