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
			while (i > n)
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
		BigInt(const string &s) : neg(s[0] == '-')
		{
			for_each(s.crbegin(), s.crend() - neg, [&](const char &c) { digit.push_back(c - '0'); });
			if (digit.size() == 1 && digit[0] == 0) neg = false;
			ntt_init();
		}
		BigInt(string &&s) : BigInt(s) {}
		BigInt(i64 &&i) : neg(i < 0)
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
		}
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
	using b = BigInt<>;
	// assert(b("9871248059959875101") * b("2451597548645885739") == b("24200327545873085124057352587957084639"));
	// assert(b("5417178119015881739") * b("7070568190868137937") == b("38302527292580585365179270453131432443"));
	// assert(b("8500329381064712267") * b("3754035012430578874") == b("31910534113709281941551852933058847358"));
	// assert(b("4384737841418311296") * b("8081474645744519175") == b("35435147693658634977625131875991100800"));
	// assert(b("1948433415680940491") * b("9094706378761168124") == b("17720429814184860104288925254090108884"));
	// assert(b("1297952944423169227") * b("1910527904790538240") == b("2479775319425507428584720223934740480"));
	// assert(b("3146240118335948676") * b("5252587216292975036") == b("16525900624959501020723844839445252336"));
	// assert(b("3178753420079614848") * b("9351388055064627833") == b("29725756762528343383768924835100864384"));
	// assert(b("1026418975796184935") * b("1408223064072214768") == b("1445426875117567996884259950366120080"));
	// assert(b("4420340833876426013") * b("3104789164637579421") == b("13724226325024569949695712014917878473"));
	// assert(b(537891253006) % b(406355) == b(358571));
	// assert(b(95971699922) % b(9438052) == b(5587186));
	// assert(b(641325680486) % b(30919259) == b(29329567));
	// assert(b(112274294521) % b(2633654) == b(1624501));
	// assert(b(591834298908) % b(47251195) == b(13081533));
	// assert(b(822370066918) % b(63394160) == b(21023398));
	// assert(b(447454199825) % b(33265597) == b(31920175));
	// assert(b(655395348763) % b(40017336) == b(31437091));
	// assert(b(611085654973) % b(29377082) == b(12972291));
	// assert(b(203928983064) % b(14485770) == b(12798774));
	// assert(b(10000) / b(9999) == b(1));
	// assert(b("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
	// 		 "0000000000000000000000000000000000000000000000000000000") %
	// 		   b("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
	// 			 "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999") ==
	// 	   b("1"));
	i64 times = 204;
	string max_a_str = "1";
	REP(i, times) max_a_str += "0000000000";
	string max_b_str = "2";
	REP(i, times) max_b_str += "0000000000";
	string max_ans_str = "1";
	REP(i, 2 * times) max_ans_str += "0000000000";
	// assert(b(move(max_a_str)) * b(move(max_b_str)) == b(move(max_ans_str)));
	// b max_nines(max_a_str)
	cout << (b(max_a_str) - b(1)) * (b(max_a_str) - b(1)) << endl;
	cout << "----" << endl;
	cout << (b(max_ans_str) - b(max_b_str) + b(1)) << endl;
	assert((b(max_a_str) - b(1)) * (b(max_a_str) - b(1)) == (b(max_ans_str) - b(max_b_str) + b(1)));
	cout << "assertion is all clear!" << endl;
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
