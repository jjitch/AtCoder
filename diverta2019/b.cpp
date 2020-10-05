#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int r, g, b, n;
    int ans = 0;
    cin >> r >> g >> b >> n;
    vector<int> c{r, g, b};
    sort(c.begin(), c.end());
    int max = c[2];
    for (auto i = 0; i <= static_cast<int>(n / max); i++)
    {
        for (auto j = 0; j <= (n - max * i) / c[1]; j++)
        {
            if ((n - max * i - c[1] * j) % c[0] == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}