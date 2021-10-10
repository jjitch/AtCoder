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
	vvi G(n);
	vvi bw(n, vi(2));
	vvi child(n);
	vi visited(n);
	stack<i64> s;
	stack<i64> backward;
	REP(i, n - 1)
	{
		IN_i64(a);
		IN_i64(b);
		a--;
		b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	s.push(0);
	visited[0] = 1;
	while (!s.empty())
	{
		i64 now = s.top();
		s.pop();
		backward.emplace(now);
		for (auto &&i : G[now])
		{
			if (visited[i]) continue;
			visited[i] = 1;
			s.emplace(i);
			child[now].emplace_back(i);
		}
	}
	while (!backward.empty())
	{
		i64 t = backward.top();
		backward.pop();
		if (!child[t].size())
		{
			bw[t][0]++;
			bw[t][1]++;
			continue;
		}
		i64 black = 1;
		i64 white = 1;
		for (auto &&i : child[t])
		{
			black *= bw[i][1];
			black %= MOD;
			white *= bw[i][0] + bw[i][1];
			white %= MOD;
		}
		bw[t][0] = black;
		bw[t][1] = white;
	}
	cout << (bw[0][0] + bw[0][1]) % MOD << endl;
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
