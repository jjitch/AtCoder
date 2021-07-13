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

struct WeightedEdge
{
    i64 from;
    i64 to;
    i64 cost;
    WeightedEdge(i64 _from, i64 _to, i64 _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator>(const WeightedEdge &other) const { return cost > other.cost; }
    bool operator<(const WeightedEdge &other) const { return cost < other.cost; }
};

int main()
{
    IN_i64(V);
    IN_i64(E);
    vector<vector<i64>> d(V, vector<i64>(V, INF64));
    rep(i, V) d[i][i] = 0;
    rep(i, E)
    {
        IN_i64(s);
        IN_i64(t);
        IN_i64(c);
        d[s][t] = c;
    }
    rep(k, V) rep(i, V) rep(j, V) if (d[i][k] != INF64 && d[k][j] != INF64) chmin(d[i][j], d[i][k] + d[k][j]);
    rep(i, V) if (d[i][i] < 0)
    {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, V)
    {
        rep(j, V)
        {
            if (d[i][j] == INF64) { cout << "INF"; }
            else
            {
                cout << d[i][j];
            }
            if (j != V - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
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
