#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
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

int main()
{
    IN_i64(n);
    IN_i64(q);
    dsu d(n);
    rep(i, q)
    {
        IN_i64(t);
        IN_i64(u);
        IN_i64(v);
        if (t == 0) d.merge(u, v);
        if (t == 1) cout << d.same(u, v) << endl;
    }
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
