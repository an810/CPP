#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int n, m; // m keo, n nguoi
int x[MAXN];
int cur_sum = 0;

void print_sol() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << "\n";
}

// void TRY(int k) {
//     // x1, x2, ..., x[k-1]: cur_sum 
//     // x[k]: 1... m - cur_sum - (n - k)
//     int start_val = k != n ? 1 : m - cur_sum - (n - k);
//     for (int v = start_val; v <= m - cur_sum - (n - k); v++) {
//         x[k] = v;
//         cur_sum += v;
//         if (k == n) {
//             if (cur_sum == m) {
//                 print_sol();
//             }
//         } else TRY(k + 1);
//         cur_sum -= v;
//     }
// }


// 2 nguoi canh nhau co so keo khac nhau 
void TRY(int k) {
    // x1, x2, ..., x[k-1]: cur_sum 
    // x[k]: 1... m - cur_sum - (n - k)
    int start_val = k != n ? 1 : m - cur_sum - (n - k);
    for (int v = start_val; v <= m - cur_sum - (n - k); v++) {
        if (x[k-1] == v) continue;
        x[k] = v;
        cur_sum += v;
        if (k == n) {
            if (cur_sum == m) {
                print_sol();
            }
        } else TRY(k + 1);
        cur_sum -= v;
    }
}

// 3 nguoi lien tiep ko co so keo tang dan VD: 2 3 4 1
// int marked[MAXN];
// bool is_cand(int i, int k) {
//     if (k<= 2) return true;
//     if (x[k-2] > x[k-1]) return true;
//     return i < x[k-1];
// }
// void TRY(int k) {
//     // x1, x2, ..., x[k-1]: cur_sum 
//     // x[k]: 1... m - cur_sum - (n - k)
//     int start_val = k != n ? 1 : m - cur_sum - (n - k);
//     for (int v = start_val; v <= m - cur_sum - (n - k); v++) {
//         if (!marked[v] && is_cand(v, k)) {
//             marked[v] = true;
//             x[k] = v;
//             cur_sum += v;
//             if (k == n) {
//                 if (cur_sum == m) {
//                     print_sol();
//                 }
//             } else TRY(k + 1);
//             cur_sum -= v;
//             marked[v] = false;
//         }
       
//     }
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    TRY(1);
    return 0;
}