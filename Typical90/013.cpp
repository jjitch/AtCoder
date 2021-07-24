#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
#define IN_i64(n) \
	i64 n; \
	cin >> n;
#define IN_veci64(a, n) \
	vector<i64> a((n)); \
	rep(i, n) cin >> a[i];
constexpr i64 INF64 = 1LL << 60LL;
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
	IN_i64(n);
	IN_i64(m);
	vector<vector<WeightedEdge>> g(n, vector<WeightedEdge>());
	rep(i, m)
	{
		IN_i64(a);
		IN_i64(b);
		IN_i64(c);
		a--;
		b--;
		g[a].emplace_back(a, b, c);
		g[b].emplace_back(b, a, c);
	}
	priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> pq;
	vector<i64> visitedFrom0(n, INF64);
	visitedFrom0[0] = 0;
	pq.emplace(0, 0, 0);
	while (!pq.empty())
	{
		auto cur(pq.top());
		pq.pop();
		if (visitedFrom0[cur.to] < cur.cost) continue;
		for (auto &&e : g[cur.to])
		{
			if (chmin(visitedFrom0[e.to], visitedFrom0[e.from] + e.cost)) { pq.push(e); }
		}
	}
	vector<i64> visitedFromN(n, INF64);
	visitedFromN[n - 1] = 0;
	pq.emplace(n - 1, n - 1, 0);
	while (!pq.empty())
	{
		auto cur(pq.top());
		pq.pop();
		if (visitedFromN[cur.to] < cur.cost) continue;
		for (auto &&e : g[cur.to])
		{
			if (chmin(visitedFromN[e.to], visitedFromN[e.from] + e.cost)) { pq.push(e); }
		}
	}
	rep(i, n) { cout << visitedFrom0[i] + visitedFromN[i] << endl; }
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
