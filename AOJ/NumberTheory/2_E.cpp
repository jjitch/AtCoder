#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
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

template <class T = int> class BigInt
{
private:
	vector<T> digit;
	bool neg;
	enum FFT
	{
		NORMAL,
		INVERSE,
	};
	void carry_and_fix()
	{
		const size_t n(digit.size());
		REP(i, n - 1)
		{
			if (digit[i] >= 10)
			{
				const T k = digit[i] / 10;
				digit[i] -= k * 10;
				digit[i + 1] += k;
			}
			if (digit[i] < 0)
			{
				const T k = (-digit[i] - 1) / 10 + 1;
				digit[i] += k * 10;
				digit[i + 1] -= k;
			}
		}
		while (digit.back() >= 10)
		{
			const T k = digit.back() / 10;
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
	vector<complex<double>> dft(const vector<complex<double>> &f, FFT TYPE)
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
		const vector<complex<double>> dft0 = dft(f0, TYPE);
		const vector<complex<double>> dft1 = dft(f1, TYPE);
		const double re(cos(2. * M_PI / static_cast<double>(n)));
		const double im(sin(2. * M_PI / static_cast<double>(n)) * (TYPE == FFT::NORMAL ? 1. : -1.));
		const complex<double> zeta(re, im);
		complex<double> zeta_pow(1., 0.);
		vector<complex<double>> ret(n);
		for (size_t i = 0; i < n; i++)
		{
			ret[i] = dft0[i % (n / 2)] + zeta_pow * dft1[i % (n / 2)];
			zeta_pow *= zeta;
		}
		return ret;
	}
	BigInt &cut_decade(size_t n)
	{
		if (n >= digit.size())
		{
			digit[0] = 0;
			while (digit.size() > 1)
			{
				digit.pop_back();
			}
			return *this;
		}
		for (size_t i = 0; i < digit.size() - n; i++)
		{
			digit[i] = digit[i + n];
		}
		for (size_t i = 0; i < n; i++)
		{
			digit.pop_back();
		}
		return *this;
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
	vector<T> getDigit() const { return digit; }
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
		const size_t n(ceil_pow(digit.size() + rhs.digit.size() - 1));
		vector<complex<double>> a(n), b(n);
		for (size_t i = 0; i < n; i++)
		{
			a[i] = complex<double>(static_cast<double>(i < digit.size() ? digit[i] : 0.), 0.);
			b[i] = complex<double>(static_cast<double>(i < rhs.digit.size() ? rhs.digit[i] : 0.), 0.);
		}
		const vector<complex<double>> dft_a(dft(a, FFT::NORMAL));
		const vector<complex<double>> dft_b(dft(b, FFT::NORMAL));
		vector<complex<double>> accum(n);
		for (size_t i = 0; i < n; i++)
		{
			accum[i] = dft_a[i] * dft_b[i];
		}
		const vector<complex<double>> ret(dft(accum, FFT::INVERSE));
		digit.resize(n, 0);
		for (size_t i = 0; i < n; i++)
		{
			digit[i] = static_cast<T>(round(ret[i].real())) / n;
		}
		neg ^= rhs.neg;
		carry_and_fix();
		return *this;
	}
	BigInt &operator/=(const BigInt &rhs)
	{
		if (abs(*this) < abs(rhs))
		{
			*this = BigInt(0);
			return *this;
		}
		const bool origin_neg(neg);
		if (abs(*this) == abs(rhs))
		{
			*this = BigInt(1);
			neg = origin_neg ^ rhs.neg;
			return *this;
		}
		if (neg) { neg = !neg; }
		size_t num_d(digit.size());
		size_t den_d(rhs.digit.size());

		string init = "1";
		for (size_t i = 0; i < num_d; i++)
		{
			init += "0";
		}
		BigInt prev(move(init));
		BigInt two(2);
		size_t cnt(0);
		while (true)
		{
			BigInt f(move((rhs.neg ? -rhs : rhs) * prev * prev));
			f.cut_decade(num_d + den_d);
			BigInt next = move(two * prev - f);

			if (next == prev) break;
			cnt++;
			if (cnt == 1000) cout << next << " " << prev << " " << rhs << endl;
			prev = move(next);
		}
		BigInt origin(*this);
		*this *= prev;
		this->cut_decade(num_d + den_d);
		if (*this * (rhs.neg ? -rhs : rhs) > origin) *this -= BigInt(1);
		if (origin_neg) neg = !neg;
		if (rhs.neg) neg = !neg;
		if (digit.size() == 1 && digit[0] == 0) neg = false;
		return *this;
	}
	BigInt &operator%=(const BigInt &rhs)
	{
		*this = move(*this - *this / rhs * rhs);
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
		for_each(bigint.digit.crbegin(), bigint.digit.crend(), [&](const T &i) { os << i; });
		return os;
	}
};
template <class T> bool operator<(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	if (lhs.getNeg() != rhs.getNeg()) return lhs.getNeg();
	const vector<T> &lhs_digit = lhs.getDigit();
	const vector<T> &rhs_digit = rhs.getDigit();
	const size_t lhs_n = lhs_digit.size();
	const size_t rhs_n = rhs_digit.size();
	if (lhs_n != rhs_n) return (lhs_n < rhs_n) ^ lhs.getNeg();
	return lexicographical_compare(lhs_digit.crbegin(), lhs_digit.crend(), rhs_digit.crbegin(), rhs_digit.crend());
}
template <class T> bool operator>(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return rhs < lhs;
}
template <class T> bool operator<=(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return !(lhs > rhs);
}
template <class T> bool operator>=(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return !(lhs < rhs);
}
template <class T> bool operator==(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return !(lhs < rhs || lhs > rhs);
}
template <class T> bool operator!=(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return !(rhs == lhs);
}
template <class T> BigInt<T> operator+(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return BigInt<T>(lhs) += rhs;
}
template <class T> BigInt<T> operator-(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return BigInt<T>(lhs) -= rhs;
}
template <class T> BigInt<T> operator*(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return BigInt<T>(lhs) *= rhs;
}
template <class T> BigInt<T> operator/(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return BigInt<T>(lhs) /= rhs;
}
template <class T> BigInt<T> operator%(const BigInt<T> &lhs, const BigInt<T> &rhs)
{
	return BigInt<T>(lhs) %= rhs;
}
template <class T> BigInt<T> abs(const BigInt<T> &x)
{
	return x.getNeg() ? -x : x;
}

int main() {
	BigInt<> a, b;
	cin >> a >> b;
	cout << a % b << endl;
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
