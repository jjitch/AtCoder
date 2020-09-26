#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> x_s(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> x_s[i];
    }
    vector<int> sub(n);
    for (auto i = 0; i < n; i++)
    {
        sub[i] = abs(x_s[i] - x);
    }
    int ans;
    for (auto i = 0; i < n; i++)
    {
        if (i==0) {
            ans = sub[i];
        }
        else
        {
            ans = gcd(ans, sub[i]);
        }
    }
    cout << ans << endl;
    return 0;
}