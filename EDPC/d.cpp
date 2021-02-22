#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

void showv(vector<ll> x){
    for (ll v : x)
    {
        cout << right << setw(4) << setfill(' ') << v;
    }
    cout << endl;
}

void showvv(vector<vector<ll>> a)
{
    for (vector<ll> x : a)
    {
        showv(x);
    }
}

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    rep(i, n) cin >> weight[i] >> value[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    rep(i, n)
    {
        rep(j, w+1)
        {
            if (j - weight[i] >= 0)
            {
                chmax(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);
            }
            chmax(dp[i + 1][j], dp[i][j]);
            // showvv(dp);
            // cout << "-----" << endl;
        }
    }
    // showvv(dp);
    cout << dp[n][w] << endl;
}
