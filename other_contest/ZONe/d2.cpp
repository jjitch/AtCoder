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
    int n = s.length();
    vector<char> c(n);
    rep(i, n) { c[i] = s[i]; }
    vector<int> r;

    for (i64 i = 0; i < (n); i++)
    {
        if (c[i] == 'R') r.push_back(i);
    }
    vector<char> sta;
    size_t pre=0;
    for (i64 i = 0; i < r.size(); i++)
    {
        if ((r.size()-i) % 2 == 0)
        {
            for_each(c.begin()+pre, c.begin() + min(r[i],n), [&](const char val) {
                if (sta.empty()) sta.push_back(val);
                else if (sta.back() != val)
                    sta.push_back(val);
                else
                    sta.pop_back();
            });
        }else {
            for_each(c.rbegin()+pre, c.rbegin() + min(r[i],n), [&](const char val) {
                if (sta.empty()) sta.push_back(val);
                else if (sta.back() != val)
                    sta.push_back(val);
                else
                    sta.pop_back();
            });
        }
        pre+=r[i]+1;
    }
    cout<<sta.data()<<endl;
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
