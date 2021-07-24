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

int main()
{
	IN_i64(n);
	vector<vector<i64>> cum(2, vector<i64>(n));
	i64 score[2];
	score[0] = score[1] = 0;
	rep(i, n)
	{
		IN_i64(c);
		IN_i64(p);
		c--;
		score[c] += p;
		cum[0][i] = score[0];
		cum[1][i] = score[1];
	}
	IN_i64(q);
	rep(i, q)
	{
		IN_i64(L);
		IN_i64(R);
		L--;
		R--;
		if (L == 0)
		{
			cout << (cum[0][R]) << " " << (cum[1][R]) << endl;
			continue;
		}
		L--;
		cout << (cum[0][R] - cum[0][L]) << " " << (cum[1][R] - cum[1][L]) << endl;
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
