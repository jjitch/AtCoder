#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    ll n;
    cin >> n;
    ll lim = sqrt(n);
    vector<int> nums(lim + 1, 0);
    ll cnt = 0;
    for (ll i = 2; i < (lim + 1); i++)
    {
        if (!nums[i])
        {
            ll tmp = i;
            while (tmp <= n)
            {
                cnt++;
                tmp*=i;
            }
            cnt--;
            for (ll pri = i; pri < (lim + 1);pri*=i){
                nums[pri]++;
            }
        }
    }
    cout << n-cnt << endl;
}
