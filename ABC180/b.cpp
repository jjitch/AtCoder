#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll tmp;
    ll man = 0;
    unsigned long euc = 0;
    ll che = 0;
    for (auto i = 0; i < n; i++)
    {
        cin >> tmp;
        man+=abs(tmp);
        euc+=tmp*tmp;
        if (abs(tmp)>che)
        {
            che=abs(tmp);
        }
        
    }
    cout << man << endl;
    cout << fixed << setprecision(15) << sqrt(euc) << endl;
    cout << che << endl;
}