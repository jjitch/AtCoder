#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr int INF32 = 1 << 30;
constexpr i64 INF64 = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

int main()
{
    i64 n, m;
    cin >> n >> m;
    vector<i64> c(m);
    rep(i, m) cin >> c[i];
    sort(c.begin(), c.end(), greater<i64>());
    i64 allcase = modpow(2, m);
    i64 ans = INF64;
    rep(state, allcase)
    {
        i64 tmp = n;
        i64 cnt = 0;
        rep(i, m)
        {
            if ((state >> i) & 1)
            {
                cnt += tmp / c[i];
                tmp %= c[i];
            }
        }
        if (tmp == 0) chmin(ans, cnt);
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
