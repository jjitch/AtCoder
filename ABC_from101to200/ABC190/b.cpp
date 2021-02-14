#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, s, d;
    cin >> n >> s >> d;
    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    bool possible = false;
    rep(i, n)
    {
        if (x[i] < s && y[i] > d)
            possible = true;
    }
    if (possible)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
