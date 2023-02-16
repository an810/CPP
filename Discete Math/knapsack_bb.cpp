#include<bits/stdc++.h>
using namespace std;

#define Max 20  

int w[100], p[100];
int x[100], xopt[100];
double A[100];
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
        } else {
            double A = -1;
            for (int j=k+1; j<=n; j++) {
                double temp = p[j]/w[j];
                if (temp > A) A = temp;
            }
            if (A*ck + fk > fopt) Try(k+1);

        } 
        fk -=p[k] * x[k];
        ck += w[k] * x[k];
    }
}

int main() {
    cin >> n >> ck;
    for (int i=1; i<=n; i++)
        cin >> p[i] >> w[i];
    for (int i=1; i<=n; i++) 
        A[i] = p[i]/w[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (A[j] > A[i])
                swap(A[j], A[i]);
        }
    }
    Try(1);
    cout << fopt;
}
