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
constexpr i64 MOD = 1000000007;
inline i64 modpow(i64, i64, i64 = 0);
inline i64 modinv(i64, i64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);
template <class T> inline void show(const vector<T> &v);

int main()
{
	IN_i64(n);
	IN_i64(k);
	IN_vi(a, n);
	i64 r, m, l;
	r = 0;
	l = 1000000000 + 10;
	m = (r + l) / 2;
	auto solve = [&](i64 b) {
		i64 cnt = 0;
		REP(i, n) cnt += (a[i] + b - 1) / b - 1;
		return cnt <= k;
	};
	m = (l + r) / 2;
	while (l - r > 1 && m != r)
	{
		if (solve(m))
			l = m;
		else
			r = m;
		m = (l + r) / 2;
	}
	cout << l << endl;
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
