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

class BigInt
{
private:
	vector<int> digit;
	bool sign;
	void carry_and_fix()
	{
		size_t n(digit.size());
		REP(i, n - 1)
		{
			if (digit[i] >= 10)
			{
				int k = digit[i] / 10;
				digit[i] -= k * 10;
				digit[i + 1] += k;
			}
			if (digit[i] < 0)
			{
				int k = (-digit[i] - 1) / 10 + 1;
				digit[i] += k * 10;
				digit[i + 1] -= k;
			}
		}
		while (digit.back() >= 10)
		{
			int k = digit.back() / 10;
			digit.back() -= k * 10;
			digit.push_back(k);
		}
		while (digit.size() >= 2 && digit.back() == 0)
		{
			digit.pop_back();
		}
	}

public:
	BigInt() : sign(false) { digit.push_back(0); }
	explicit BigInt(string &&s) : sign(s[0] == '-')
	{
		for_each(s.crbegin(), s.crend() - sign, [&](const char &c) { digit.push_back(c - '0'); });
	}
	explicit BigInt(i64 &&i) : sign(i < 0)
	{
		if (sign) i = -i;
		while (i > 0)
		{
			digit.push_back(i % 10);
			i /= 10;
		}
	}
	bool getSign() const { return sign; }
	vector<int> getDigit() const { return digit; }
	BigInt &operator+=(const BigInt &rhs)
	{
		size_t n(max(digit.size(), rhs.digit.size()));
		for (size_t i = 0; i < n; i++)
		{
			if (i >= digit.size()) { digit.push_back(rhs.digit[i]); }
			else
				digit[i] += i < rhs.digit.size() ? rhs.digit[i] : 0;
		}
		carry_and_fix();
		return *this;
	};
	friend istream &operator>>(istream &is, BigInt &bigint)
	{
		string s;
		is >> s;
		bigint = std::move(BigInt(std::move(s)));
		return is;
	}
	friend ostream &operator<<(ostream &os, const BigInt &bigint)
	{
		if (bigint.sign) os << '-';
		for_each(bigint.digit.crbegin(), bigint.digit.crend(), [&](const int &i) { os << i; });
		return os;
	}
};

bool operator<(const BigInt &lhs, const BigInt &rhs)
{
	if (lhs.getSign() != rhs.getSign()) return lhs.getSign();
	if (lhs.getDigit().size() != rhs.getDigit().size())
		return lhs.getDigit().size() < rhs.getDigit().size() ^ lhs.getSign();
	size_t i(lhs.getDigit().size());
	do
	{
		i--;
		if (lhs.getDigit()[i] < rhs.getDigit()[i]) return true;
	} while (i != 0);
	return false;
}
bool operator>(const BigInt &lhs, const BigInt &rhs)
{
	return rhs < lhs;
}
bool operator<=(const BigInt &lhs, const BigInt &rhs)
{
	return !(lhs > rhs);
}
bool operator>=(const BigInt &lhs, const BigInt &rhs)
{
	return !(lhs < rhs);
}

int main()
{
	using b = BigInt;
	assert(b("4564") < b("45465"));
	assert(b("4546") > b("45"));
	assert(b("122") >= b("121"));
	assert(b("122") >= b("122"));
	assert(b("122") <= b("122"));
	assert(b("122") <= b("123"));
	cout << (b(56) += b(4546)) << endl;
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
