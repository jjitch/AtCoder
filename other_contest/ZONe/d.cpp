#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr i64 INFLL = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INFLL);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

int main()
{
    string s;
    cin >> s;
    size_t n = s.length();
    vector<char> c(n);
    rep(i, n) c[i] = s[i];
    vector<char> sa();
    vector<int> rev();
    rep(i, n)
    {
        if (c[i] == 'R') rev.push_back(i);
    }
    for (int boo:rev){
        if (boo%2==1){

        }
    }
}

i64 modpow(i64 base, i64 exp, i64 mod)
{
    i64 ans = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        exp /= 2;
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
