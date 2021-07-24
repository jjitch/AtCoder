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
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

/* BIT2D:
	初期値は全て 0
	・add(h,w,x): (h,w) に x を加算する
	・sum(h,w): 1≦i≦h かつ 1≦j≦w の範囲の合計値を求める
	・query(h1,w1,h2,w2): h1≦i<h2 かつ w1≦j<w2 の範囲の合計値を求める(1-indexed)
	計算量は全て O(logW * logH)
*/
template <typename T> struct BIT2D
{
	int H, W;
	vector<vector<T>> bit; // データの格納先
	BIT2D(int H_, int W_) { init(H_, W_); }
	void init(int H_, int W_)
	{
		H = H_ + 1;
		W = W_ + 1;
		bit.assign(H, vector<T>(W, 0));
	}

	void add(int h, int w, T x)
	{
		for (int i = h; i < H; i += (i & -i))
		{
			for (int j = w; j < W; j += (j & -j))
			{
				bit[i][j] += x;
			}
		}
	}
	// 1≦i≦h かつ 1≦j≦w
	T sum(int h, int w)
	{
		T s(0);
		for (int i = h; i > 0; i -= (i & -i))
		{
			for (int j = w; j > 0; j -= (j & -j))
			{
				s += bit[i][j];
			}
		}
		return s;
	}

	// h1≦i<h2 かつ w1≦j<w2
	T query(int h1, int w1, int h2, int w2)
	{
		return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) + sum(h1 - 1, w1 - 1);
	}
};

int main()
{
	IN_i64(n);
	BIT2D<int> bit2;
	bit2.init(10010, 10010);
	REP(i,n){

	}
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
