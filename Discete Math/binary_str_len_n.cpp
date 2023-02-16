#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
//return 1 if the current solution is final
bool checkFinal() {
    for(int i =1; i<=n; i++)
        if(a[i]==0) return 0;
    return 1;
}

void Successive_Generation(){
    //create the next solution of the current solution
    int i = n;
    while (a[i] == 1) {
        a[i] = 0;
        i--;
    }
    a[i] = 1;
}

void Generate() {
    for(int  i=1; i<=n; i++) a[i] = 0;
    bool stop = 0;
    while(!stop){
        //Build the first solution
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
        if(!checkFinal()){
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