#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    ll ans = 0;
    cin >> s;
    for (auto i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
        {
            ans += s.length() - i-1;
            ans += 2 * i;
        }
        else
        {
            ans += 2 * (s.length() - i-1);
            ans += i;
        }
    }
    cout << ans << endl;
}