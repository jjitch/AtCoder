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

int main()
{
    string s;
    cin >> s;
    vector<int> flag(10);
    rep(i, 10)
    {
        if (s[i] == 'o') flag[i] = 1;
        if (s[i] == '?') flag[i] = 0;
        if (s[i] == 'x') flag[i] = -1;
    }
    set<int> exist;
    i64 ans = 0;
    rep(i, 10000)
    {
        bool possible = true;
        std::ostringstream sout;
        sout << std::setfill('0') << std::setw(4) << i;
        string tmp_s = sout.str();
        rep(j, 5) { exist.insert(tmp_s[j] - '0'); }
        rep(j, 10)
        {
            if (flag[j] == 1)
            {
                if (exist.find(j) == exist.end()) possible = false;
            }
            if (flag[j] == -1)
            {
                if (exist.find(j) != exist.end()) possible = false;
            }
        }
        if (possible) ans++;
        exist.clear();
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
