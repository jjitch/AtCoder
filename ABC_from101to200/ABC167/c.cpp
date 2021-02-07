#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n)
    {
        cin >> c[i];
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    int all_state = pow(2, n);
    int cost = 0;
    bool possible = true;
    int ans = 1<<30;
    vector<int> ex(m, 0);
    rep(state, all_state)
    {
        rep(i, n)
        {
            if ((state >> i) & 1 == 1)
            {
                cost += c[i];
                rep(j, m)
                {
                    ex[j] += a[i][j];
                }
            }
        }
        rep(j, m)
        {
            if (ex[j] < x)
            {
                possible = false;
            }
        }
        if (possible)
        {
            ans = min(ans, cost);
        }
        rep(j,m){
            ex[j] = 0;
        }
        cost = 0;
        possible = true;
    }
    if (ans == 1<<30)
    {
        ans = -1;
    }
    cout << ans << endl;
}
