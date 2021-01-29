#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    char previous = ' ';
    unordered_set<string> us;
    bool first = false;
    bool second = false;
    bool found = false;
    for (int i = 0; i < N; i++)
    {
        string w;
        cin >> w;
        if (*(w.end() - 1) == previous && !found)
        {
            if (i % 2 == 0)
            {
                second = true;
            }
            else
            {
                first = true;
            }
            found = true;
        }
        ;
        if (!us.insert(w).second && !found) {
            if (i % 2 == 0)
            {
                second = true;
            }
            else
            {
                first = true;
            }
            found = true;
        }
    }
    if (second) {
        cout << "LOSE" << endl;
    } else if (first)
    {
        cout << "WIN" << endl;
    } else {
        cout << "DRAW" << endl;
    }
}