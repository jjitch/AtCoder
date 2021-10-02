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

int main()
{
	string n;
	cin >> n;
	vi dig;
	i64 zero = 0;
	for (auto &&i : n)
	{
		if (i - '0' == 0)
			zero++;
		else
			dig.emplace_back(i - '0');
	}
	i64 aa = (1 << dig.size()) - 1;
	i64 ans = 0;
	REP(allstate, aa)
	{
		vi a, b;
		if (!allstate) continue;
		REP(i, dig.size())
		{
			if ((allstate >> i) & 1) { a.push_back(dig[i]); }
			else
			{
				b.push_back(dig[i]);
			}
		}
		SORT(a);
		i64 a_num = 0;
		while (!a.empty())
		{
			a_num *= 10;
			a_num += a.back();
			a.pop_back();
		}
		SORT(b);
		i64 b_num = 0;
		while (!b.empty())
		{
			b_num *= 10;
			b_num += b.back();
			b.pop_back();
		}
		ans = max(ans, a_num * b_num);
	}
	REP(i, zero) { ans *= 10; }
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
