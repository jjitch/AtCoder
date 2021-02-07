#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a != x)
        {
            ans.push_back(a);
        }
    }
    string anss ="";
    string ab = "asaav";
    for (int v : ans)
    {
        char add = v;
        anss.push_back(v);
        anss.push_back(' ');
    }
    anss.pop_back();
    cout << anss << endl;
    cout << ab << endl;
}
