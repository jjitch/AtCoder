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
	pii c;
	cin >> c.first >> c.second;
	c.first--;
	c.second--;
	pii d;
	cin >> d.first >> d.second;
	d.first--;
	d.second--;
	vvi maze(h, vi(w));
	REP(i, h)
	{
		string s;
		cin >> s;
		REP(j, w) { maze[i][j] = s[j] == '.' ? 1 : 0; }
	}
	vvi cost(h, vi(w, INF64));
	deque<pii> q;
	q.push_front(c);
	cost[c.first][c.second] = 0;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop_front();
		REP(i, 4)
		{
			pii adj = {now.first + dx[i], now.second + dy[i]};
			if (adj.first < 0 || h <= adj.first || adj.second < 0 || w <= adj.second) continue;
			if (!maze[adj.first][adj.second]) continue;
			if (chmin(cost[adj.first][adj.second], cost[now.first][now.second])) q.push_front(adj);
		}
		REP(i, 5) REP(j, 5)
		{
			pii adj = {now.first + i - 2, now.second + j - 2};
			if (adj.first < 0 || h <= adj.first || adj.second < 0 || w <= adj.second) continue;
			if (!maze[adj.first][adj.second]) continue;
			if (chmin(cost[adj.first][adj.second], cost[now.first][now.second] + 1)) q.push_back(adj);
		}
	}
	if (cost[d.first][d.second] == INF64) { cout << -1 << endl; }
	else
	{
		cout << cost[d.first][d.second] << endl;
	}
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
