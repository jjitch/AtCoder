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
constexpr i64 INF64 = 1LL << 60LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

constexpr i64 MAX_N = 110;
constexpr i64 MAX_W = 10010;
i64 dp[MAX_N][MAX_W];

int main()
{
	rep(i, MAX_N) rep(j, MAX_W) dp[i][j] = 0;
	IN_i64(N);
	IN_i64(W);
	vector<i64> v(N), w(N);
	rep(i, N)
	{
		IN_i64(a);
		IN_i64(b);
		v[i] = a;
		w[i] = b;
	}
	rep(i, N) rep(j, W + 1)
	{
		if (j >= w[i]) chmax(dp[i][j], dp[i][j - w[i]] + v[i]);
		if (i > 0) chmax(dp[i][j], dp[i - 1][j]);
	}
	cout << dp[N - 1][W] << endl;
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
