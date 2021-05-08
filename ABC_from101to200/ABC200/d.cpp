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
#define printa(x, n) \
    for (int i = 0; i < n; i++) \
    { \
        cout << (x[i]) << " "; \
    } \
    cout << endl;
constexpr i64 INF64 = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    IN_i64(n);
    IN_veci64(a, n);
    vector<pair<i64, i64>> cnt(210, pair<i64, i64>{0, 0});
    i64 num = min(n, 10LL);
    i64 all_state = modpow(2, num);
    for (i64 state = 1; state < all_state; state++)
    {
        i64 s = 0;
        for (i64 i = 0; i < num; i++)
        {
            if ((state >> i) & 1) { s += a[i]; }
        }
        s %= 200;
        cnt[s].first++;
        if (cnt[s].first > 1)
        {
            i64 xy = 0;
            cout << "Yes\n";
            for (i64 i = 0; i < num; i++)
                if ((state >> i) & 1) xy++;
            cout << xy;
            for (i64 i = 0; i < num; i++)
                if ((state >> i) & 1) cout << " " << i + 1;
            cout << "\n";
            xy = 0;
            i64 prev = cnt[s].second;
            for (i64 i = 0; i < num; i++)
                if ((prev >> i) & 1) xy++;
            cout << xy;
            for (i64 i = 0; i < num; i++)
                if ((prev >> i) & 1) cout << " " << i + 1;
            cout << "\n";
            return 0;
        }
        cnt[s].second = state;
    }
    cout << "No\n";
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
