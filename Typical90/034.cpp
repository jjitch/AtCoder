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
	IN_i64(k);
	IN_vi(a, n);
	vi decoder = a;
	sort(decoder.begin(), decoder.end());
	decoder.erase(unique(decoder.begin(), decoder.end()), decoder.end());
	i64 r = 0;
	i64 l = 0;
	map<i64, i64> encoder;
	REP(i, decoder.size()) { encoder.emplace(decoder[i], i); }
	vi a_comp(n);
	REP(i, n) a_comp[i] = encoder[a[i]];
	vi cnt(n);
	i64 kind = 0;
	i64 ans = 0;
	while (r < n)
	{
		if (!cnt[a_comp[r]]) kind++;
		cnt[a_comp[r]]++;
		while (kind > k)
		{
			cnt[a_comp[l]]--;
			if (!cnt[a_comp[l]]) kind--;
			l++;
		}
		r++;
		chmax(ans, r - l);
	}
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
