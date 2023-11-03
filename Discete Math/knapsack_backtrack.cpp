#include<bits/stdc++.h>
using namespace std;

#define Max 20  

int w[100], p[100];
int x[100], xopt[100];
int n, c, ck, fk;
int fopt = INT_MIN;

void Try(int k) {
    int t = ck/w[k];
    for (int i=0; i<=t; i++) {
        x[k] =i;
        fk += p[k] * x[k];
        ck -= w[k] * x[k];
        if (k == n) {
            if (fk > fopt) {
                fopt=fk;
                for (int i=1; i<=n; i++)
                    xopt[i] = x[i];
            }
        } else Try(k+1);
        fk -=p[k] * x[k];
        ck += w[k] * x[k];
    }
}

int main() {
    cin >> n >> ck;
    for (int i=1; i<=n; i++)
        cin >> p[i] >> w[i];
    Try(1);
    cout << fopt;
}
