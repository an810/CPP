#include <bits/stdc++.h>
using namespace std;

#define FOR(x,a,b,i) for (int x=(a),_b=(b),_i=(i);x<=_b;x+=_i)
#define FOD(x,a,b,i) for (int x=(a),_b=(b),_i=(i);x>=_b;x-=_i)
#define FOV(it,v) for (auto it=v.begin();it!=v.end();it++) 
#define MOD (1e9+7)
#define ll long long

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

int random(int l,int r)
{
    return 1 + rand() % (r - l + 1);
}

int main()
{
}