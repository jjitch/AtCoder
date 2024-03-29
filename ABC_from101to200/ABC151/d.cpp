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

i64 dx[4] = {1, 0, -1, 0};
i64 dy[4] = {0, 1, 0, -1};

int main()
{
	IN_i64(h);
	IN_i64(w);
	vvi maze(h, vi(w));
	REP(i, h)
	{
		string s;
		cin >> s;
		REP(j, w) { maze[i][j] = s[j] == '.' ? 1 : 0; }
	}
	i64 ans = 0;
	REP(i, h) REP(j, w)
	{
		if (!maze[i][j]) continue;
		vvi initial(h, vi(w, INF64));
		initial[i][j] = 0;
		queue<pii> q;
		i64 furthest = 0;
		q.emplace(i, j);
		while (!q.empty())
		{
			pii now = q.front();
			q.pop();
			REP(k, 4)
			{
				i64 idx = now.first + dx[k];
				i64 jdy = now.second + dy[k];
				if (idx < 0 || h <= idx || jdy < 0 || w <= jdy) continue;
				if (!maze[idx][jdy]) continue;
				if (chmin(initial[idx][jdy], initial[now.first][now.second] + 1))
				{
					q.emplace(idx, jdy);
					chmax(furthest, initial[idx][jdy]);
				}
			}
		}
		chmax(ans, furthest);
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
	{
		if (v[i] == INF64)
		{
			cout << "# ";
			continue;
		}
		cout << v[i] << " ";
	}
	if (v[n] == INF64)
	{
		cout << "#\n";
		return;
	}
	cout << v[n] << "\n";
}
