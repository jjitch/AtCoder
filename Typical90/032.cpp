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
	vvi record(n);
	REP(i, n)
	{
		IN_vi(a, n);
		record[i] = a;
	}
	IN_i64(m);
	vvi relate(n, vi(n, 1));
	REP(i, m)
	{
		IN_i64(a);
		IN_i64(b);
		a--;
		b--;
		relate[a][b] = 0;
		relate[b][a] = 0;
	}
	vi order(n);
	REP(i, n) { order[i] = i; }
	i64 ans = INF64;
	do
	{
		bool possible = true;
		REP(i, n - 1)
		{
			if (!relate[order[i]][order[i + 1]]) possible = false;
		}
		if (!possible) continue;
		i64 accum = 0;
		REP(i, n) accum += record[order[i]][i];
		chmin(ans, accum);
	} while (next_permutation(order.begin(), order.end()));
	if (ans == INF64)
		cout << -1 << endl;
	else
		cout << ans << endl;
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
