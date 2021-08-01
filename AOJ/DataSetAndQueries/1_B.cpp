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

struct WeightedUnionFind
{
	vector<int> root, rank;
	vector<i64> diff_weight;
	WeightedUnionFind(i64 num)
	{
		root.resize(static_cast<size_t>(num), -1);
		rank.resize(static_cast<size_t>(num), 1);
		diff_weight.resize(static_cast<size_t>(num), 0);
	}
	bool isRoot(size_t i) { return root[i] == -1; }
	size_t find(size_t i)
	{
		if (isRoot(i)) return i;
		diff_weight[i] += diff_weight[root[i]];
		return root[i] = find(root[i]);
	}
	bool isSame(size_t a, size_t b) { return find(a) == find(b); }
	bool unite(size_t a, size_t b, i64 w)
	{
		const size_t root_a(find(a));
		const size_t root_b(find(b));
		if (isSame(a, b)) return false;
		root[root_a] = root_b;
		diff_weight[root_a] += w;
		return true;
	}
	i64 weight(size_t i)
	{
		find(i);
		return diff_weight[i];
	}
	i64 diff(size_t a, size_t b) { return isSame(a, b) ? weight(b) - weight(a) : INF64; }
};

ostream& operator<<(ostream& os, const WeightedUnionFind& wuf){
	os << "root\n";
	for (auto &&i : wuf.root)
	{
		os << setw(3) << i << " ";
	}
	os << "\nrank\n";
	for (auto &&i : wuf.rank)
	{
		os << setw(3) << i << " ";
	}
	os << "\ndiff_weight\n";
	for (auto &&i : wuf.diff_weight)
	{
		os << setw(3) << i << " ";
	}
	return os;
}

int main()
{
	WeightedUnionFind wuf(5);
	wuf.unite(0, 1, 5);
	cout << wuf << endl;
	cout << wuf.diff(0, 1) << endl;
	// IN_i64(n);
	// WeightedUnionFind wuf(n);
	// IN_i64(q);
	// REP(i, q)
	// {
	// 	IN_i64(t);
	// 	if (t)
	// 	{
	// 		IN_i64(a);
	// 		IN_i64(b);
	// 		if (wuf.diff(a, b) == INF64) { cout << "?" << endl; }
	// 		else
	// 		{
	// 			cout << wuf.diff(a, b) << endl;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		IN_i64(a);
	// 		IN_i64(b);
	// 		IN_i64(w);
	// 		wuf.unite(a, b, w);
	// 	}
	// }
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
