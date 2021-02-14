#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, m;
int cnt = 0;

void dfs(vector<int> a)
{
    if (a.size() == n + 1)
    {
        rep(i, n)
        {
            cout << a[i + 1] << " ";
        }
        cout << endl;
        cnt++;
        return;
    }

    a.push_back(a.back());
    while (a.back() <= m)
    {
        dfs(a);
        a.back()++;
    }
}

int main()
{
    cin >> n >> m;
    dfs({1});
    cout << cnt << endl;
}
