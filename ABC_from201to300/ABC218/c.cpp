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
inline i64 modpow(i64, i64, i64 = 0);
inline i64 modinv(i64, i64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

int main()
{
	IN_i64(n);
	vector<string> s(n);
	vector<string> t(n);
	REP(i, n) cin >> s[i];
	REP(i, n) cin >> t[i];
	vi si_0;
	vi ti_0;
	REP(i, n) REP(j, n)
	{
		if (s[i][j] == '#') si_0.emplace_back(n * i + j);
		if (t[i][j] == '#') ti_0.emplace_back(n * i + j);
	}
	i64 diff = si_0[0] - ti_0[0];
	if (si_0.size() != ti_0.size())
	{
		cout << "No" << endl;
		exit(0);
	}
	bool possible = true;
	REP(i, si_0.size())
	{
		if (si_0[i] - ti_0[i] != diff) possible = false;
	}
	if (possible)
	{
		cout << "Yes" << endl;
		exit(0);
	}
	//
	vi si_90;
	REP(i, n) REP(j, n)
	{
		if (s[n - j - 1][i] == '#') si_90.emplace_back(n * i + j);
	}
	diff = si_90[0] - ti_0[0];
	possible = true;
	REP(i, si_90.size())
	{
		if (si_90[i] - ti_0[i] != diff) possible = false;
	}
	if (possible)
	{
		cout << "Yes" << endl;
		exit(0);
	}
	//
	vi si_180;
	REP(i, n) REP(j, n)
	{
		if (s[n - i - 1][n - j - 1] == '#') si_180.emplace_back(n * i + j);
	}
	diff = si_180[0] - ti_0[0];
	possible = true;
	REP(i, si_180.size())
	{
		if (si_180[i] - ti_0[i] != diff) possible = false;
	}
	if (possible)
	{
		cout << "Yes" << endl;
		exit(0);
	}
	//
	vi si_270;
	REP(i, n) REP(j, n)
	{
		if (s[j][n - i - 1] == '#') si_270.emplace_back(n * i + j);
	}
	diff = si_270[0] - ti_0[0];
	possible = true;
	REP(i, si_270.size())
	{
		if (si_270[i] - ti_0[i] != diff) possible = false;
	}
	if (possible)
	{
		cout << "Yes" << endl;
		exit(0);
	}
	//
	cout << "No" << endl;
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
