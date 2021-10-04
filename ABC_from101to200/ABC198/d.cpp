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
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	vector<char> cset;
	for (auto &&i : s1)
		cset.push_back(i);

	for (auto &&i : s2)
		cset.push_back(i);

	for (auto &&i : s3)
		cset.push_back(i);

	
	SORT(cset);
	cset.erase(unique(cset.begin(), cset.end()), cset.end());
	if (cset.size() > 10)
	{
		cout << "UNSOLVABLE" << endl;
		return 0;
	}
	vi nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do
	{
		vi alpha(26);
		REP(i, cset.size()) { alpha[cset[i] - 'a'] = nums[i]; }
		if (alpha[s1[0] - 'a'] == 0 || alpha[s2[0] - 'a'] == 0 || alpha[s3[0] - 'a'] == 0) continue;
		i64 n1 = 0, n2 = 0, n3 = 0;
		for (auto &&i : s1)
		{
			n1 *= 10;
			n1 += alpha[i - 'a'];
		}
		for (auto &&i : s2)
		{
			n2 *= 10;
			n2 += alpha[i - 'a'];
		}
		for (auto &&i : s3)
		{
			n3 *= 10;
			n3 += alpha[i - 'a'];
		}
		if (n1 + n2 == n3)
		{
			cout << n1 << "\n" << n2 << "\n" << n3 << endl;
			return 0;
		}

	} while (next_permutation(nums.begin(), nums.end()));
	cout << "UNSOLVABLE" << endl;
	return 0;
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
