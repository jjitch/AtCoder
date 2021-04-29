#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
constexpr ll INFLL = 1LL << 62LL;
ll powll(ll, ll, ll = INFLL);

int main()
{
    size_t n;
    cin >> n;
    ll all_state = powll(2, n);
    for (size_t state = 0; state < all_state; state++)
    {
        
        vector<char> ans;
        bool proper = true;
        size_t left = 0, right = 0;
        int judge = 0;
        for (size_t i = 0; i < n; i++)
        {
            if ((state >> i) & 1)
            {
                judge++;
                right++;
                ans.push_back(')');
            }
            else
            {
                judge--;
                left++;
                ans.push_back('(');
            }
            if (judge < 0)
            {
                proper = false;
            }
        }
        if (proper&&(left==right))
        {
            for_each(ans.rbegin(), ans.rend(), [](const char &c) { cout << c; });
            cout << endl;
        }
    }
}

ll powll(ll base, ll exp, ll mod)
{
    ll ans = 1;
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
