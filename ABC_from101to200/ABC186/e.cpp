#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int extGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        int n, s, k;
        int x, y;
        cin >> n >> s >> k;
        int d=extGCD(n,-k,x,y);
        cout << "gcd: " << d << endl;
        cout << x << " " << y << endl;
        cout << "---" << endl;
    }
}
