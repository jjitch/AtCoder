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
inline i64 modpow(i64, i64, i64 = 0);
inline i64 modinv(i64, i64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

namespace
{
	template <class T = i64> class BigInt
	{
	private:
		i64 NTT_MOD;
		i64 NTT_ROOT;
		vector<i64> NTT_ROOTS;
		vector<i64> NTT_INV_ROOTS;
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
				digit.pop_back();
			if (digit.size() == 1 && digit[0] == 0) neg = false;
		}
		size_t ceil_pow(const size_t i)
		{
			size_t n = 1;
			while (i >= n)
				n <<= 1;
			return n;
		}
		BigInt &cut_decade(size_t n)
		{
			if (n >= digit.size())
			{
				digit[0] = 0;
				while (digit.size() > 1)
					digit.pop_back();
				return *this;
			}
			for (size_t i = 0; i < digit.size() - n; i++)
				digit[i] = digit[i + n];
			for (size_t i = 0; i < n; i++)
				digit.pop_back();
			return *this;
		}
		void ntt_init()
		{
			NTT_MOD = 0x3b800001;
			NTT_ROOT = modpow(3, 119, NTT_MOD);
			NTT_ROOTS.resize(24, 0);
			NTT_INV_ROOTS.resize(24, 0);
			i64 temp_root = NTT_ROOT;
			i64 inv_root = modinv(NTT_ROOT, NTT_MOD);
			for (size_t i = 0; i < 24; i++)
			{
				NTT_ROOTS[24 - i - 1] = temp_root;
				NTT_INV_ROOTS[24 - i - 1] = inv_root;
				temp_root *= temp_root;
				temp_root %= NTT_MOD;
				inv_root *= inv_root;
				inv_root %= NTT_MOD;
			}
		}
		vector<T> ntt(const vector<T> &f, FFT TYPE)
		{
			if (f.size() == 1) return f;
			const size_t n(f.size());
			vector<T> f0;
			vector<T> f1;
			for (size_t i = 0; i < n; i++)
				i % 2 == 0 ? f0.push_back(f[i]) : f1.push_back(f[i]);
			const vector<T> dft0 = ntt(f0, TYPE);
			const vector<T> dft1 = ntt(f1, TYPE);
			size_t root_n = 0;
			for (size_t i = 0; i < 24; i++)
				if ((n >> i) & 1) root_n = i;
			const i64 zeta = TYPE == FFT::NORMAL ? NTT_ROOTS[root_n] : NTT_INV_ROOTS[root_n];
			i64 zeta_pow = 1;
			vector<T> ret(n);
			for (size_t i = 0; i < n; i++)
			{
				ret[i] = dft0[i % (n / 2)] + zeta_pow * dft1[i % (n / 2)];
				ret[i] %= NTT_MOD;
				zeta_pow *= zeta;
				zeta_pow %= NTT_MOD;
			}
			return ret;
		}

	public:
		void show_roots()
		{
			REP(i, 24) { cout << BigInt::NTT_ROOTS[i] << " "; }
			cout << endl;
			REP(i, 24) { cout << BigInt::NTT_INV_ROOTS[i] << " "; }
			cout << endl;
		}
		BigInt() : neg(false)
		{
			digit.push_back(0);
			ntt_init();
		}
		explicit BigInt(string &&s) : neg(s[0] == '-')
		{
			for_each(s.crbegin(), s.crend() - neg, [&](const char &c) { digit.push_back(c - '0'); });
			if (digit.size() == 1 && digit[0] == 0) neg = false;
			ntt_init();
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
			ntt_init();
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
				for_each(digit.begin(), digit.end(), [](T &i) { i = -i; });
				neg = !neg;
				carry_and_fix();
			}
			return *this;
		};
		BigInt &operator-=(const BigInt &rhs) { return *this += -rhs; }
		BigInt &operator*=(const BigInt &rhs)
		{
			const size_t n(ceil_pow(digit.size() + rhs.digit.size() - 1));
			vector<T> a(n), b(n);
			for (size_t i = 0; i < n; i++)
			{
				a[i] = i < digit.size() ? digit[i] : 0;
				b[i] = i < rhs.digit.size() ? rhs.digit[i] : 0;
			}
			const vector<T> dft_a(ntt(a, FFT::NORMAL));
			const vector<T> dft_b(ntt(b, FFT::NORMAL));
			vector<T> accum(n);
			for (size_t i = 0; i < n; i++)
				accum[i] = dft_a[i] * dft_b[i] % NTT_MOD;
			const vector<T> ret(ntt(accum, FFT::INVERSE));
			digit.resize(n, 0);
			for (size_t i = 0; i < n; i++)
				digit[i] = ret[i] / n;
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
			const size_t num_d(digit.size());
			const size_t den_d(rhs.digit.size());
			string init = "1";
			for (size_t i = 0; i < num_d; i++)
				init += "0";
			BigInt prev(move(init));
			const BigInt two(2);
			while (true)
			{
				BigInt f(move((rhs.neg ? -rhs : rhs) * prev * prev));
				f.cut_decade(num_d + den_d);
				BigInt next = move(two * prev - f);
				if (next == prev) break;
				prev = move(next);
			}
			const BigInt origin(*this);
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
	template <class T> bool operator>(const BigInt<T> &lhs, const BigInt<T> &rhs) { return rhs < lhs; }
	template <class T> bool operator<=(const BigInt<T> &lhs, const BigInt<T> &rhs) { return !(lhs > rhs); }
	template <class T> bool operator>=(const BigInt<T> &lhs, const BigInt<T> &rhs) { return !(lhs < rhs); }
	template <class T> bool operator==(const BigInt<T> &lhs, const BigInt<T> &rhs) { return !(lhs < rhs || lhs > rhs); }
	template <class T> bool operator!=(const BigInt<T> &lhs, const BigInt<T> &rhs) { return !(rhs == lhs); }
	template <class T> BigInt<T> operator+(const BigInt<T> &lhs, const BigInt<T> &rhs) { return BigInt<T>(lhs) += rhs; }
	template <class T> BigInt<T> operator-(const BigInt<T> &lhs, const BigInt<T> &rhs) { return BigInt<T>(lhs) -= rhs; }
	template <class T> BigInt<T> operator*(const BigInt<T> &lhs, const BigInt<T> &rhs) { return BigInt<T>(lhs) *= rhs; }
	template <class T> BigInt<T> operator/(const BigInt<T> &lhs, const BigInt<T> &rhs) { return BigInt<T>(lhs) /= rhs; }
	template <class T> BigInt<T> operator%(const BigInt<T> &lhs, const BigInt<T> &rhs) { return BigInt<T>(lhs) %= rhs; }
	template <class T> BigInt<T> abs(const BigInt<T> &x) { return x.getNeg() ? -x : x; }
} // namespace

int main()
{
	BigInt<> a, b;
	cin >> a >> b;
	cout << a * b << endl;
}

i64 modpow(i64 base, i64 ex, i64 mod)
{
	i64 ans = 1;
	while (ex)
	{
		if (ex & 1 == 1)
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

i64 gcd(i64 a, i64 b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
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
