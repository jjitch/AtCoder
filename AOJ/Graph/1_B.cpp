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

struct WeightedEdge
{
    i64 from;
    i64 to;
    i64 cost;
    WeightedEdge(i64 _from, i64 _to, i64 _cost) : from(_from), to(_to), cost(_cost) {}
};

int main()
{
    IN_i64(v);
    IN_i64(e);
    IN_i64(r);
    vector<WeightedEdge> G;
    i64 cnt(0);
    vector<i64> dist(v, INF64);
    for (size_t i = 0; i < e; i++)
    {
        IN_i64(s);
        IN_i64(t);
        IN_i64(d);
        G.emplace_back(s, t, d);
    }
    dist[r] = 0;
    while (true)
    {
        bool updated(false);
        for (const WeightedEdge &g : G)
        if (dist[g.from]!=INF64)
            updated |= chmin(dist[g.to], dist[g.from] + g.cost);
        if (!updated) break;
        cnt++;
        if (cnt == v)
        {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (i64 d : dist)
    {
        if (d == INF64)
        {
            cout << "INF" << endl;
            continue;
        }
        cout << d << endl;
    }
}

i64 modpow(i64 base, i64 pwr, i64 mod)
{
    i64 ans = 1;
    while (pwr > 0)
    {
        if (pwr % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        pwr /= 2;
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
