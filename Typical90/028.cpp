#define _USE_MATH_DEFINES
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
constexpr i64 MOD = 1000000007;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

int main()
{
	IN_i64(n);
	const i64 lim(1005);
	vvi area(lim, vi(lim));
	REP(i, n)
	{
		IN_i64(lx);
		IN_i64(ly);
		IN_i64(rx);
		IN_i64(ry);
		area[lx][ly]++;
		area[rx][ry]++;
		area[lx][ry]--;
		area[rx][ly]--;
	}
	REP(i, lim) REP(j, lim - 1) area[i][j + 1] += area[i][j];
	REP(j, lim) REP(i, lim - 1) area[i + 1][j] += area[i][j];
	vi ans(n + 1);
	REP(i, lim) REP(j, lim) { ans[area[i][j]]++; }
	for (size_t i = 1; i < n + 1; i++)
		cout << ans[i] << endl;
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
