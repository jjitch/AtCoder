#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
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
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

struct UnionFind
{
	vector<int> root, rank;
	UnionFind(i64 num)
	{
		root.resize(static_cast<size_t>(num), -1);
		rank.resize(static_cast<size_t>(num), 1);
	}
	bool isRoot(size_t i) { return root[i] == -1; }
	size_t find(size_t i) { return isRoot(i) ? i : root[i] = find(root[i]); }
	bool isSame(size_t a, size_t b) { return find(a) == find(b); }
	bool unite(size_t a, size_t b)
	{
		if (isSame(a, b)) return false;
		const size_t root_a(find(a));
		const size_t root_b(find(b));
		const size_t high = rank[root_a] > rank[root_b] ? root_a : root_b;
		const size_t lower = rank[root_a] > rank[root_b] ? root_b : root_a;
		chmax(rank[high], rank[lower] + 1);
		root[lower] = high;
		return true;
	}
};

int main()
{
	IN_i64(h);
	IN_i64(w);
	UnionFind uf(h * w);
	vi paper(h * w);
	IN_i64(q);
	REP(i, q)
	{
		IN_i64(qt);
		if (qt == 1)
		{
			IN_i64(r);
			IN_i64(c);
			i64 pos(w * (r - 1) + c - 1);
			paper[pos] = 1;
			if (c != 1 && paper[pos - 1]) uf.unite(pos, pos - 1);
			if (c != w && paper[pos + 1]) uf.unite(pos, pos + 1);
			if (r != 1 && paper[pos - w]) uf.unite(pos, pos - w);
			if (r != h && paper[pos + w]) uf.unite(pos, pos + w);
		}
		else
		{
			IN_i64(ra);
			IN_i64(ca);
			IN_i64(rb);
			IN_i64(cb);
			i64 pos_a(w * (ra - 1) + ca - 1);
			i64 pos_b(w * (rb - 1) + cb - 1);
			if (paper[pos_b] && paper[pos_a] && uf.isSame(pos_a, pos_b))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
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
