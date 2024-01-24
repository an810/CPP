#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FOR(x,a,b,i) for (int x=(a),_b=(b),_i=(i);x<=_b;x+=_i)
#define FOD(x,a,b,i) for (int x=(a),_b=(b),_i=(i);x>=_b;x-=_i)
#define ll long long
#define max(a,b) (a>b)? a:b
#define min(a,b) (a<b)? a:b
#define MOD 1000000007

int n,k,q;
int g[100][100];
int d[100];
int used[100];
int maxn;
ll res=INT_MAX;
ll cost[8510];
ll cost0[8510];
ll dp[10][8510];

void init()
{
    FOR(i,1,n,1)
    {
        maxn|=(1<<i);
    }
    FOR(i,2,8500,1)
    {
        cost[i]=INT_MAX;
        cost0[i]=INT_MAX;
    }
    FOR(i,1,k,1)
        FOR(mask,2,8500,1)
            dp[i][mask]=INT_MAX;
}

int mask=0;
void Try(int cur,int cap,int cost)
{
    FOR(j,1,n,1)
        if (used[j]==0 && cap>=d[j])
        {
            used[j]=1;
            mask|=(1<<j);
            cost0[mask]=min(cost0[mask],cost+g[cur][j]+g[j][0]);
            Try(j,cap-d[j],cost+g[cur][j]);
            mask&=~(1<<j);
            used[j]=0;
        }
}

void sol()
{
    init();

    Try(0,q,0);

    FOR(mask,2,maxn,1)
    {
        dp[1][mask]=cost0[mask];
    }

    FOR(i,1,k-1,1)
    {
        FOR(mask1,2,maxn,1)
            FOR(mask2,2,maxn,1)
                if ((mask1&mask2)==0)
                {
                    dp[i+1][mask1|mask2]=min(dp[i+1][mask1|mask2],dp[i][mask1]+cost0[mask2]);
                }
    }

    FOR(i,1,k,1)
        res=min(res,dp[i][maxn]);
    printf("%lld\n",res);
}

int main()
{
    // freopen("VRP.out","w",stdout);
    scanf("%d%d%d",&n,&k,&q);
    FOR(i,1,n,1) scanf("%d",&d[i]);
    FOR(i,0,n,1)
        FOR(j,0,n,1)    
            scanf("%d",&g[i][j]);
    int b[]={0,6,5,3,2,1,4};
    sol();
}