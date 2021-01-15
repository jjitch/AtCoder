#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    deque<ll> dq;
    ll n;
    cin >> n;
    ll r = static_cast<ll>(sqrt(n));
    ll num=0;
    while (r>0)
    {
        if (n%r==0)
        {
            if (n/r==r)
            {
                dq.push_front(r);
                num++;
            }
            else
            {
                dq.push_front(r);
                dq.push_back(n/r);
                num+=2;
            }
        }
        r--;
    }
    for (auto i = 0; i < num; i++)
    {
        cout << dq[i] << endl;
    }
    for (auto e:dq)
    {
        cout << e << endl;
    }
    
}