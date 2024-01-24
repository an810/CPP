#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int,int>> cond;
vector<int> draw(5001, 0);
int tmp = 0;
vector<int> res;
int max_ans = 0;

int main(){
    cin >> n >>k;
    for(int i = 1; i <= k; i++){
        cin >> cond[i].first >> cond[i].second;
        cout << cond[i].first << cond[i].second;
        for(int j = cond[i].first; j <= cond[i].second; j++){
            draw[j] ++;
        }
    }
    for(int i = 1; i < k; i++){
        for(int j = i+1; j <= k; i++){
            for(int l = cond[i].first; l <= cond[i].second; l++){
                draw[l] --;
            }
            for(int l = cond[j].first; l <= cond[j].second; l++){
                draw[l] --;
            }
            for(int l = 1; l <= n; l++){
                if(draw[l] > 0){
                    tmp ++;
                }
            }
            res.push_back(tmp);
            tmp = 0;
        }
    }
    for(int i = 0; i < res.size(); i++){
        if(max_ans < res[i]) max_ans = res[i];
    }
    cout<< max_ans;
    return 0;
}