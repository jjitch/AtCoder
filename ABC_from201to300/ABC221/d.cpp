#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;
using i64 = long long;
using vi = vector<i64>;
using vvi = vector<vi>;
#define REP(i, n) for (i64 i = 0; i < static_cast<i64>(n); i++)
#define IN_i64(n) \
	i64 n; \
	cin >> n;
#define IN_vi(a, n) \
	vi a((n)); \
	REP(i, n) cin >> a[i];
#define SHOW(v) \
	REP(i, v.size() - 1) cout << v[i] << " "; \
	cout << v.back() << "\n";
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
constexpr i64 INF64 = 1LL << 60LL;
constexpr i64 MOD = 1000000007;
inline i64 modpow(i64, i64, i64 = 0);
inline i64 modinv(i64, i64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

using pii = pair<i64, i64>;
int main()
{
	IN_i64(n);
	vector<pii> e(2 * n);
	REP(i, n)
	{
		IN_i64(s);
		IN_i64(t);
		s--;
		e[i].first = s;
		e[i].second = 1;
		e[i + n].first = s + t;
		e[i + n].second = -1;
	}
	SORT(e);
	i64 now = 0;
	i64 people = 0;
	vi cnt(n);
	REP(i, 2 * n)
	{
		if (e[i].second == -1)
		{
			people--;
			if (now != e[i].first)
			{
				cnt[people] += e[i].first - now;
				now = e[i].first;
			}
		}
		if (e[i].second == 1)
		{
			people++;
			if (now != e[i].first)
			{
				cnt[people] += e[i].first - now;
				now = e[i].first;
			}
		}
	}
	REP(i, n) { cout << cnt[i] << endl; }
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
