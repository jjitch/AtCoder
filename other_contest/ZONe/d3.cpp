#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (size_t i = 0; i < (n); i++)
constexpr i64 INFLL = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INFLL);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);


int main()
{
    string s;
    cin >> s;
    deque<char> d;
    bool rev = false;
    int rev_cnt=0;
    rep(i,s.length()) {
        if (s[i]=='R'){
            rev = rev? false:true;
            rev_cnt++;
            continue;
        }
        if (rev){
            if(d.empty()||d.front()!=s[i]) d.push_front(s[i]);
            else d.pop_front();
        }
        else {
            if (d.empty()||d.back() != s[i]) d.push_back(s[i]);
            else
                d.pop_back();
        }
    }
    vector<char> ans;
    for (char c : d) ans.push_back(c);
    if (rev_cnt%2==1) reverse(ans.begin(),ans.end());
    rep(i, ans.size()) cout<<ans[i];
    cout<<endl;
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
