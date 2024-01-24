#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Union_Find {
    vector<int> iParent;
    Union_Find(int n) {
        iParent = vector<int>(n);
        for (int i=0; i<n; i++)
            iParent[i]=i;
    }

    int Find(int x) {
        if (iParent[x] == x) {
            return x;
        } else {
            iParent[x] = Find(iParent[x]);
            return iParent[x];
        }
    }
    void Unite(int x, int y) {
        iParent[Find(x)] = Find(y);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    
    return 0;
}