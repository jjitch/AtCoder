#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr i64 INFLL = 1LL << 62LL;
i64 powll(i64, i64, i64 = INFLL);
inline i64 gcd(i64, i64);

int main()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 g = gcd(a, gcd(b, c));
    cout << (a + b + c) / g - 3 << endl;
}

i64 powll(i64 base, i64 exp, i64 mod)
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

inline i64 gcd(i64 a, i64 b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
