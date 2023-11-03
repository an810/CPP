#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[100];

bool checkFinal(){
    for (int i=1; i<=m; i++)
        if (a[i] != n-m+i) return 0;
    return 1;
}

void Successive_Generation() {
    int i = m;
    while (a[i] == n-m+i) {
        i--;
    }
    a[i] += 1;
    for (int j=i+1; j<=m; j++) {
        a[j] = a[i]+j-i;
    }
}

void Generate(){
    for(int i=1; i<= m; i++) a[i] = i;
    bool stop = 0; 
    while(!stop){
        for (int i=1; i<=m; i++) cout << a[i] << " ";
        cout << "\n";
        if (!checkFinal()){
            Successive_Generation();
        }
        else stop = 1;
    }
}

int main() {
    cin >> n >> m;
    Generate();
    return 0;
}