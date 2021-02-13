#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, m, q;

int ans;

int solve(vector<int> a, vector<vector<int>> query)
{
    int score = 0;
    rep(i, q)
    {
        if (a[query[i][1]] - a[query[i][0]] == query[i][2])
        {
            score += query[i][3];
        }
    }
    return score;
}

void dfs(int add, int step, vector<int> a, vector<vector<int>> &query)
{
    if (step != 0)
    {
        a.push_back(add);
    }
    if (step == n)
    {
        ans = max(ans, solve(a, query));
        return;
    }
    step++;
    for (int i = step; i <= m; i++)
    {
        dfs(i, step, a, query);
    }
}

int main()
{
    cin >> n >> m >> q;
    vector<vector<int>> queries(q, vector<int>(4));
    rep(i, q)
    {
        rep(j, 4)
        {
            cin >> queries[i][j];
        }
        queries[i][0]--;
        queries[i][1]--;
    }
    vector<int> a = {};
    dfs(0, 0, a, queries);
    cout << ans << endl;
}
