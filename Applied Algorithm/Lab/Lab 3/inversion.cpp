#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000000

int const MOD =  1e9+7;

int n, a[N], temp[N];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

int mergeArray(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inv_count = 0;
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid - i + 1)) % MOD;
        }
    }
    // Copy nhung phan tu con lai cua nua ben trai (neu co) vao mang trung gian
    while (i <= mid) temp[k++] = a[i++];
    // Copy nhung phan tu con lai cua nua ben phai (neu co) vao mang trung gian
    while (j <= right) temp[k++] = a[j++];
    // Copy nhung phan tu da duoc hop nhat vao mang goc
    for (int i = left; i <= right; i++) a[i] = temp[i];
    return inv_count;
}

int mergeSort(int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        // Divide the array into 2 parts and call mergeSort() for each of the parts
        mid = (left + right) / 2;
        // Inversion count will be sum of inversion in left-part, right-part and number of inversions in merging 
        inv_count = (inv_count + mergeSort(left, mid)) % MOD;
        inv_count = (inv_count + mergeSort(mid+1, right)) % MOD;
        inv_count = (inv_count + mergeArray(left, mid, right)) % MOD;
    }
    return inv_count;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    cout << mergeSort(1, n);
    return 0;
}