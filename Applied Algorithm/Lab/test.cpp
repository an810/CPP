#include <iostream>
#include <vector>

using namespace std;
int arr[100000];
int n;
int x; 
int m;
int cnt;
int sum;
int visited[100000] = {0};
int result[10000];

int check(int v, int k)
{
    if (k == x)
        return sum + arr[v] == m;
    else return 1;
}

void prinConfiguration()
{
    for (int i = 1; i <= x; i++)
        cout << result[i] << " ";
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (visited[v] == 0 && check(v,k))
        {
            visited[v] = 1;
            sum += arr[v];
            result[k] = arr[v];
            if (k == x)
            {
                prinConfiguration();
            }
            else Try(k+1);
            visited[v] = 0;
            sum -= arr[v];
        }
    }
}

int main(void)
{

    cin >> n >> x >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    Try(1);
    cout << cnt << endl;
}