#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    unsigned long long n;
    cin >> n;
    for (auto three = 1; three < 40; three++)
    {
        for (auto five = 1; five < 30; five++)
        {
            if (pow(3, three) + pow(5, five) == n)
            {
                cout << three << " " << five << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}