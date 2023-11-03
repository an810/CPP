#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

bool CheckFinal(){
    for (int i=1; i<=n; i++)
        if (a[i] != n-i+1) return 0;
    return 1;
}

void Successive_Generation(){
    int j = n-1;
    while (a[j] > a[j+1])
        j--;
    int k = n;
    while (a[j] > a[k])
        k--;
    swap(a[j], a[k]);
    int r = n, l = j+1;
    while (r>l){
        swap(a[r], a[l]);
        r--;
        l++;
    }
}

void Generate(){
    for (int i=1; i<=n; i++) a[i] = i;
    bool stop = 0;
    while(!stop){
        for (int i=1; i<=n; i++) cout << a[i] << " ";
        cout << "\n";
        if (!CheckFinal()){
            Successive_Generation();
        }
        else stop = 1;
    }
}

int main(){
    cin >> n;
    Generate();
    return 0;
}   