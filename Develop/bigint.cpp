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
	bool neg;
	void carry_and_fix()
	{
		const size_t n(digit.size());
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
		if (digit.size() == 1 && digit[0] == 0) neg = false;
	}
	size_t ceil_pow(const size_t i)
	{
		size_t n = 1;
		while (i > n)
		{
			n <<= 1;
		}
		return n;
	}
	vector<complex<double>> dft(const vector<complex<double>> &f)
	{
		if (f.size() == 1) return f;
		const size_t n(f.size());
		vector<complex<double>> f0;
		vector<complex<double>> f1;
		for (size_t i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				f0.push_back(f[i]);
			else
				f1.push_back(f[i]);
		}
		vector<complex<double>> dft0 = dft(f0);
		vector<complex<double>> dft1 = dft(f1);
		complex<double> zeta(cos(2. * M_PI / static_cast<double>(n)), sin(2. * M_PI / static_cast<double>(n)));
		complex<double> zeta_pow(1., 0.);
		vector<complex<double>> ret(n);
		for (size_t i = 0; i < n; i++)
		{
			ret[i] = f0[i % (n / 2)] + zeta_pow * f1[i % (n / 2)];
			zeta_pow *= zeta;
		}
		return ret;
	}
	vector<complex<double>> inverse_dft(const vector<complex<double>> &f)
	{
		if (f.size() == 1) return f;
		size_t n(f.size());
		vector<complex<double>> f0, f1;
		for (size_t i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				f0.push_back(f[i]);
			else
				f1.push_back(f[i]);
		}
		vector<complex<double>> dft0 = inverse_dft(f0);
		vector<complex<double>> dft1 = inverse_dft(f1);
		complex<double> zeta(cos(-2. * M_PI / static_cast<double>(n)), sin(-2. * M_PI / static_cast<double>(n)));
		complex<double> zeta_pow(1., 0.);
		vector<complex<double>> ret(n);
		for (size_t i = 0; i < n; i++)
		{
			ret[i] = f0[i % (n / 2)] + zeta_pow * f1[i % (n / 2)];
			zeta_pow *= zeta;
		}
		return ret;
	}

public:
	BigInt() : neg(false) { digit.push_back(0); }
	explicit BigInt(string &&s) : neg(s[0] == '-')
	{
		for_each(s.crbegin(), s.crend() - neg, [&](const char &c) { digit.push_back(c - '0'); });
		if (digit.size() == 1 && digit[0] == 0) neg = false;
	}
	explicit BigInt(i64 &&i) : neg(i < 0)
	{
		if (i == 0) digit.push_back(0);
		if (neg) i = -i;
		while (i > 0)
		{
			digit.push_back(i % 10);
			i /= 10;
		}
	}
	bool getNeg() const { return neg; }
	vector<int> getDigit() const { return digit; }
	BigInt operator-() const
	{
		BigInt b(*this);
		b.neg = !b.neg;
		return b;
	}
	BigInt operator+() const
	{
		BigInt b(*this);
		return b;
	}
	BigInt &operator+=(const BigInt &rhs)
	{
		size_t n(max(digit.size(), rhs.digit.size()));
		bool diff(neg ^ rhs.neg);
		for (size_t i = 0; i < n; i++)
		{
			if (i >= digit.size()) { digit.push_back(diff ? -rhs.digit[i] : rhs.digit[i]); }
			else
				digit[i] += i < rhs.digit.size() ? diff ? -rhs.digit[i] : rhs.digit[i] : 0;
		}
		carry_and_fix();
		if (digit.back() < 0)
		{
			for_each(digit.begin(), digit.end(), [](int &i) { i = -i; });
			neg = !neg;
			carry_and_fix();
		}
		return *this;
	};
	BigInt &operator-=(const BigInt &rhs) { return *this += -rhs; }
	BigInt &operator*=(const BigInt &rhs)
	{
		const size_t n(ceil_pow(digit.size() + rhs.digit.size() - 2));
		vector<complex<double>> a(n), b(n);
		for (size_t i = 0; i < n; i++)
		{
			a[i] = i < digit.size() ? complex<double>(static_cast<double>(digit[i]), 0.) : 0;
			b[i] = i < rhs.digit.size() ? complex<double>(static_cast<double>(rhs.digit[i]), 0.) : 0;
		}
		vector<complex<double>> dft_a(dft(a));
		vector<complex<double>> dft_b(dft(b));
		vector<complex<double>> accum(n);
		for (size_t i = 0; i < n; i++)
		{
			accum[i] = dft_a[i] * dft_b[i];
		}
		vector<complex<double>> ret(inverse_dft(accum));
		digit.resize(n, 0);
		for (size_t i = 0; i < n; i++)
		{
			digit[i] = static_cast<int>(accum[i].real()) / n;
		}
		neg = neg ^ rhs.neg;
		return *this;
	}
	friend istream &operator>>(istream &is, BigInt &bigint)
	{
		string s;
		is >> s;
		bigint = std::move(BigInt(std::move(s)));
		return is;
	}
	friend ostream &operator<<(ostream &os, const BigInt &bigint)
	{
		if (bigint.neg) os << '-';
		for_each(bigint.digit.crbegin(), bigint.digit.crend(), [&](const int &i) { os << i; });
		return os;
	}
};
bool operator<(const BigInt &lhs, const BigInt &rhs)
{
	if (lhs.getNeg() != rhs.getNeg()) return lhs.getNeg();
	if (lhs.getDigit().size() != rhs.getDigit().size())
		return lhs.getDigit().size() < rhs.getDigit().size() ^ lhs.getNeg();
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
bool operator==(const BigInt &lhs, const BigInt &rhs)
{
	return !(lhs < rhs || lhs > rhs);
}
bool operator!=(const BigInt &lhs, const BigInt &rhs)
{
	return !(rhs == lhs);
}
BigInt operator+(const BigInt &lhs, const BigInt &rhs)
{
	return BigInt(lhs) += rhs;
}
BigInt operator-(const BigInt &lhs, const BigInt &rhs)
{
	return BigInt(lhs) -= rhs;
}
BigInt operator*(const BigInt &lhs, const BigInt &rhs) {
	return BigInt(lhs) *= rhs;
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
	assert(b("-25") == -b("25"));
	assert(b("232") == (b(200) += b(32)));
	assert(b(-23) == (b(-20) += b(-3)));
	assert(b(-10) == (b(20) += b(-30)));
	assert(b(190) == (b(-10) += b(200)));
	assert(b(-70) == (b(30) -= b(100)));
	assert(b(88) == b(48) + b(40));
	assert(b(8) == b(48) - b(40));
	assert(b("200000000000000000000000000") == b("100000000000000000000000000") + b("100000000000000000000000000"));
	assert(b("-0") == b("0"));
	assert(b(0) == b(-0));
	cout << (b(100) *= b(100)) << endl;
	// assert(b("100") * b("100") == b("10000"));
	assert(b(-70) * b(8) == b(-560));
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
