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

i64 fact(i64 n)
{
    if (n == 0) return 1;
    return n * fact(n - 1);
}

i64 comb(i64 n, i64 r)
{
    return fact(n) / fact(r) / fact(n - r);
}

int main()
{
    string s;
    cin >> s;
    int ok, que, ng;
    ok = que = ng = 0;
    rep(i, 10)
    {
        if (s[i] == 'o') ok++;
        if (s[i] == '?') que++;
        if (s[i] == 'x') ng++;
    }
    i64 ans = 0;
    if (ok == 0)
    {
        if (que > 0) ans += que;
        if (que > 1) ans += comb(que, 2) * (4 + 6);
        if (que > 2) ans += comb(que, 3) * fact(4) / fact(2);
        if (que > 3) ans += comb(que, 4) * fact(4);
    }
    else if (ok == 1)
    {
        ans++;
        if (que > 0) ans += que * (4 + 6 + 4);
        if (que > 1) ans += comb(que, 2) * fact(4);
        if (que > 2) ans += comb(que, 3) * fact(4);
    }
    else if (ok == 2)
    {
        ans+=6+8;
        if (que > 0) ans += que * 36;
        if (que > 1) ans += comb(que, 2) * fact(4);
    }
    else if (ok == 3)
    {
        ans+=36;
        if (que > 0) ans += que * fact(4);
    }
    else if (ok == 4)
    {
        ans += fact(4);
    }
    cout << ans << endl;
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
