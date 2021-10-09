#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using i64 = long long;
using vi = vector<i64>;
using vvi = vector<vi>;
using pii = pair<i64, i64>;
#define REP(i, n) for (i64 i = 0; i < static_cast<i64>(n); i++)
#define IN_i64(n) \
	i64 n; \
	cin >> n;
#define IN_vi(a, n) \
	vi a((n)); \
	REP(i, n) cin >> a[i];
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
constexpr i64 INF64 = 1LL << 60LL;
constexpr i64 MOD = 998244353;
inline i64 modpow(i64, i64, i64 = 0);
inline i64 modinv(i64, i64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);
template <class T> inline void show(const vector<T> &v);

int main()
{
	IN_i64(n);
	IN_vi(a, n);
	IN_vi(b, n);
	vvi dp(3010, vi(3010, 0));
	for (i64 i = a[0]; i <= b[0]; i++)
	{
		dp[0][i]++;
	}
	for (i64 i = 1; i < n; i++)
	{
		i64 prev_sum = 0;
		REP(j, a[i])
		{
			prev_sum += dp[i - 1][j];
			prev_sum %= MOD;
		}
		dp[i][a[i]] += prev_sum + dp[i - 1][a[i]];
		dp[i][a[i]] %= MOD;
		for (i64 j = a[i] + 1; j <= b[i]; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= MOD;
		}
	}
	i64 ans = 0;
	for (i64 i = a[n - 1]; i <= b[n - 1]; i++)
	{
		ans += dp[n - 1][i];
		ans %= MOD;
	}
	cout << ans << endl;
}

i64 modpow(i64 base, i64 ex, i64 mod)
{
	i64 ans = 1;
	while (ex)
	{
		if (ex & 1)
		{
			ans *= base;
			if (mod) ans %= mod;
		}
		ex >>= 1;
		base *= base;
		if (mod) base %= mod;
	}
	return ans;
}

i64 modinv(i64 a, i64 mod)
{
	i64 b = mod;
	i64 x = 1;
	i64 y = 0;
	while (b)
	{
		i64 t = a / b;
		a -= t * b;
		swap(a, b);
		x -= t * y;
		swap(x, y);
	}
	x %= mod;
	if (x < 0) x += mod;
	return x;
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

template <class T> inline void show(const vector<T> &v)
{
	const i64 n = static_cast<i64>(v.size()) - 1;
	for (i64 i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << v[n] << "\n";
}
