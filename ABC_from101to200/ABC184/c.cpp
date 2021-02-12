#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int euc(int a, int b)
{
    return abs(a) + abs(b);
}

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int x = r2 - r1;
    int y = c2 - c1;
    int ans;
    if (x == 0 && y == 0)
    {
        ans = 0;
    }
    else if (x == y || x == -y || euc(x, y) <= 3)
    {
        ans = 1;
    }
    else if (abs(x - y) <= 3 || abs(x + y) <= 3 || euc(x, y) <= 6 || x % 2 == y % 2)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }
    cout << ans << endl;
}
