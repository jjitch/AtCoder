#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

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
const ll INF = 1LL << 60;

int main()
{
    int n;
    ll h[100010];
    ll dp[100010];
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (auto i = 0; i < n; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;

    for (auto i = 1; i < n; i++)
    {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1)
        {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[n - 1] << endl;
}