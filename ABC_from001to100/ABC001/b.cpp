#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int m;
    cin >> m;
    int v;
    if (m < 100)
    {
        v = 0;
    }
    else if (m >= 100 and m <= 5000)
    {
        m *= 10;
        v = m / 1000;
    }
    else if (m >= 6000 and m <= 30000)
    {
        m /= 1000;
        v = m + 50;
    }
    else if (m >= 35000 and m <= 70000)
    {
        m -= 30000;
        m /= 5;
        m += 80000;
        m /= 1000;
        v = m;
    }
    else if (m > 70)
    {
        v = 89;
    }

    cout << setfill('0') << right<< setw(2) << v << endl;
}
