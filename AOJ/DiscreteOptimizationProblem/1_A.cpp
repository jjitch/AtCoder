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

constexpr i64 N_MAX = 50010;
constexpr i64 M_MAX = 22;

int main()
{
    IN_i64(n);
    IN_i64(m);
    IN_veci64(c, m);
    sort(c.begin(), c.end());
    // vector<vector<i64>> dp(C_MAX, vector<i64>(N_MAX, INF64));
    vector<i64> dp(N_MAX,INF64);
    dp[0]=0;
    rep(i, m) rep(sum_v, N_MAX) {
        if (sum_v - c[i]>=0) chmin(dp[sum_v], dp[sum_v - c[i]] + 1);
    }
    cout<<dp[n]<<endl;
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
