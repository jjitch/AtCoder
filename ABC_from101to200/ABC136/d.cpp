#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    string s;
    cin >> s;
    vector<string> unit;
    vector<int> bnd, ini;
    vector<int> ans(s.size(), 0);
    int bnd_cnt = 0;
    int i = 0;
    string c;
    while (i < s.size())
    {
        ini.push_back(i);
        while (s[i] == 'R')
        {
            c.push_back('R');
            i++;
            bnd_cnt++;
        }
        bnd.push_back(bnd_cnt);
        bnd_cnt = 0;
        while (s[i] == 'L')
        {
            c.push_back('L');
            i++;
        }
        unit.push_back(c);
        c = {};
    }

    rep(i, ini.size())
    {
        int t = unit[i].size();
        ans[ini[i] + bnd[i] - 1] = t / 2;
        ans[ini[i] + bnd[i]] = t / 2;
        if (t % 2 == 1)
        {
            if (bnd[i] % 2 == 1)
                ans[ini[i] + bnd[i] - 1]++;
            else
                ans[ini[i] + bnd[i]]++;
        }
    }
    rep(i,s.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}
