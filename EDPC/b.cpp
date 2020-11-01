#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    vector<ll> dp(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = INF;
    }
    for (auto i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[0] = 0;
            continue;
        }

        for (auto j = max(0, i - k); j < i; j++)
        {
            chmin(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1] << endl;
}