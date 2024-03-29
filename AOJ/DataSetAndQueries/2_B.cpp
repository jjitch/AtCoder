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

template <class T> struct FenwickTree
{
	vector<T> arr;
	FenwickTree(size_t n) { arr.resize(n + 1); }
	void add(size_t n, T x)
	{
		while (n <= arr.size())
		{
			arr[n] += x;
			n += n & (-n);
		}
	}
	T subsum(size_t n)
	{
		T res = 0;
		while (n > 0)
		{
			res += arr[n];
			n -= n & (-n);
		}
		return res;
	}
	T sum(size_t l, size_t r) { return subsum(r) - subsum(l - 1); }
};

int main()
{
	IN_i64(n);
	IN_i64(q);
	FenwickTree<i64> ft(n);
	REP(i, q)
	{
		IN_i64(com);
		IN_i64(x);
		IN_i64(y);
		if (com) { cout << ft.sum(x, y) << endl; }
		else
		{
			ft.add(x, y);
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
