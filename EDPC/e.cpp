#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr i64 INFLL = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INFLL);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

constexpr i64 sum_v_MAX = 100050;
constexpr i64 N_MAX = 110;

int main()
{
    i64 n, W;
    cin >> n >> W;
    vector<i64> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    vector<vector<i64>> dp(N_MAX, vector<i64>(sum_v_MAX, INFLL));
    dp[0][0] = 0;
    rep(i, n) rep(sum_v, sum_v_MAX)
    {
        chmin(dp[i + 1][sum_v], dp[i][sum_v]);
        if (sum_v + v[i] < sum_v_MAX) chmin(dp[i + 1][sum_v + v[i]], dp[i][sum_v] + w[i]);
    }
    i64 ans = 0;
    rep(sum_v, sum_v_MAX)
    {
        if (dp[n][sum_v] <= W) ans = sum_v;
    }
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
