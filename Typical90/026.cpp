#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using vi = vector<i64>;
using vvi = vector<vi>;
#define REP(i, n) for (i64 i = 0; i < (n); i++)
#define IN_i64(n) \
	i64 n; \
	cin >> n;
#define IN_vi(a, n) \
	vi a((n)); \
	REP(i, n) cin >> a[i];
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
constexpr i64 INF64 = 1LL << 60LL;
constexpr i64 MOD = 1000000007;
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
	vector<vector<WeightedEdge>> graph(n);
	REP(i, n - 1)
	{
		IN_i64(a);
		IN_i64(b);
		a--;
		b--;
		graph[a].emplace_back(a, b, 0);
		graph[b].emplace_back(b, a, 0);
	}
	vector<int> parity(n);
	vector<int> visited(n);
	queue<WeightedEdge> q;
	visited[0] = 1;
	for (auto &&e : graph[0])
	{
		q.push(e);
	}
	while (!q.empty())
	{
		WeightedEdge next = q.front();
		q.pop();
		if (!parity[next.from]) parity[next.to] = 1;
		for (auto &&e : graph[next.to])
		{
			if (visited[e.to]) continue;
			visited[e.to] = 1;
			q.push(e);
		}
	}
	vector<i64> even, odd;
	REP(i, n)
	{
		if (parity[i])
			odd.push_back(i + 1);
		else
			even.push_back(i + 1);
	}
	if (even.size() >= n / 2)
	{
		REP(i, n / 2 - 1) { cout << even[i] << " "; }
		cout << even[n / 2 - 1] << endl;
	}
	else
	{
		REP(i, n / 2 - 1) { cout << odd[i] << " "; }
		cout << odd[n / 2 - 1] << endl;
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
