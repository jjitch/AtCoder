#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
#define IN_i64(n) \
    i64 n; \
    cin >> n;
#define IN_veci64(a, n) \
    vector<i64> a((n)); \
    rep(i, n) cin >> a[i];
constexpr i64 INF64 = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

constexpr i64 N_MAX = 110;
constexpr i64 W_MAX = 10010;

int main()
{
    IN_i64(n);
    IN_i64(W);
    vector<i64> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];
    vector<vector<i64>> dp(N_MAX, vector<i64>(W_MAX, 0));
    rep(i, n)
    {
        rep(sum_w, W_MAX)
        {
            chmax(dp[i + 1][sum_w], dp[i][sum_w]);
            if (sum_w - w[i] >= 0) chmax(dp[i + 1][sum_w], dp[i][sum_w - w[i]] + v[i]);
        }
    }
    i64 ans = 0;
    rep(i, W_MAX) if (i <= W) chmax(ans, dp[n][i]);
    cout << ans << endl;
}

i64 modpow(i64 base, i64 exp, i64 mod)
{
    i64 ans = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        exp /= 2;
        base *= base;
        base %= mod;
    }
    return ans;
}

i64 gcd(i64 a, i64 b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T> inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
