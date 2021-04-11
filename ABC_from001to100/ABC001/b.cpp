#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int assignment;
    cin >> assignment;
    int v;
    if (assignment < 100)
    {
        v = 0;
    }
    else if (assignment >= 100 and assignment <= 5000)
    {
        assignment *= 10;
        v = assignment / 1000;
    }
    else if (assignment >= 6000 and assignment <= 30000)
    {
        assignment /= 1000;
        v = assignment + 50;
    }
    else if (assignment >= 35000 and assignment <= 70000)
    {
        assignment -= 30000;
        assignment /= 5;
        assignment += 80000;
        assignment /= 1000;
        v = assignment;
    }
    else if (assignment > 70)
    {
        v = 89;
    }

    cout << setfill('0') << right<< setw(2) << v << endl;
}
