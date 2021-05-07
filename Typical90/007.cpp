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
    i64 n;
    cin>>n;
    vector<i64> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    i64 q;
    cin>>q;
    i64 b;
    while (q>0)
    {
        cin>>b;
        auto low = lower_bound(a.begin(),a.end(),b);
        i64 i = distance(a.begin(), low);
        if (i==0)
        {
            cout<<a[0]-b<<endl;
        } else if (i==n)
        {
            cout<<b-a[n-1]<<endl;
        }else{
            cout<<min(abs(a[i]-b),abs(b-a[i-1]))<<endl;
        }
        q--;
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
