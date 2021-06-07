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

constexpr int n_max = 100009;
constexpr int s_max = 10;
int dp[n_max][s_max];

int main()
{
    IN_i64(N);
    string s;
    string name = "_atcoder";
    cin >> s;
    s = "_" + s;
    rep(i, n_max) rep(j, s_max) dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (name[j + 1] == s[i + 1])
            {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= 1000000007;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= 1000000007;
        }
    }
    cout << dp[N][7] << endl;
}

i64 modpow(i64 base, i64 ex, i64 mod)
{
    i64 ans = 1;
    while (ex > 0)
    {
        if (ex % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        ex /= 2;
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
