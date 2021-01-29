#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define max(a, b) a > b ? a : b;

int main()
{
    int n;
    cin >> n;
    vi up(106);
    vi up_cum(106, 0);
    vi low(106);
    vi dp(106, 0);
    rep(i, n) cin >> up[i];
    rep(i, n) cin >> low[i];
    up_cum[0] = up[0];
    for (int i = 1; i < n; i++)
    {
        up_cum[i] = up[i] + up_cum[i - 1];
    }
    rep(i, n)
    {
        if (i == 0)
        {
            dp[i] = up[i] + low[i];
        }
        else
        {
            dp[i] = max(dp[i-1]+low[i], up_cum[i]+low[i]);
        }
    }
    cout << dp[n-1] << endl;
}