#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LARGE 2000000000
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

ll seek_sum(int t, vector<ll> a)
{
}

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int l = 0; l < n; l++)
    {
        int m = LARGE;
        for (int r = l; r < n; r++)
        {
            m = min(m, a[r]);
        }
    }
}