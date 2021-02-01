#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<ll> p(65);
vector<string> s(65);

ll assign_pow(int n)
{
    if (n <= 0)
    {
        p[0] = 1;
    }
    else
    {
        p[n] = assign_pow(n - 1) * 2;
    }
    return p[n];
}

ll solve(int n){
    if (n==0) {
        return 1;
    }
    ll ret = solve(n - 1);
    if (s[n-1]=="OR"){
        ret += p[n];
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    assign_pow(n+1);
    rep(i, n) cin >> s[i];
    cout << solve(n) << endl;
}
