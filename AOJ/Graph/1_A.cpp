#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr i64 INF64 = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

struct WeightedEdge
{
    i64 to;
    i64 cost;
    WeightedEdge(i64 _to, i64 _cost) : to(_to), cost(_cost) {}
    bool operator>(const WeightedEdge &other) const { return cost > other.cost; }
    bool operator<(const WeightedEdge &other) const { return cost < other.cost; }
};

int main()
{
    i64 V, E, r;
    cin >> V >> E >> r;
    vector<vector<WeightedEdge>> vertex(V, vector<WeightedEdge>());
    rep(i, E)
    {
        i64 s, t, d;
        cin >> s >> t >> d;
        vertex[s].emplace_back(t, d);
    }
    priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> pq;
    vector<i64> visited(V, INF64);
    visited[r] = 0;
    pq.emplace(r, 0);
    while (!pq.empty())
    {
        WeightedEdge current = pq.top();
        pq.pop();
        if (visited[current.to] > current.cost) continue;
        for (WeightedEdge &next : vertex[current.to])
        {
            if (visited[next.to] > visited[current.to] + next.cost)
            {
                visited[next.to] = visited[current.to] + next.cost;
                pq.emplace(next.to, visited[next.to]);
            }
        }
    }
    rep(i, V)
    {
        if (visited[i] == INF64) cout << "INF" << endl;
        else
            cout << visited[i] << endl;
    }
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
