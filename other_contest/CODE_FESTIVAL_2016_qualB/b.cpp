#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int c = a + b;
    string s;
    cin >> s;
    int pass = 0;
    int forlign = 0;
    rep(i, n)
    {
        if (s[i] == 'a')
        {
            if (pass < c)
            {
                pass++;
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (s[i] == 'b')
        {
            if (pass < c && forlign < b)
            {
                pass++;
                forlign++;
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
