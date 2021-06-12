#include <bits/stdc++.h>
using namespace std;

int dp[4005][4005], n, m, i, j;
string s, t;

void func(int m, int n)
{
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else
            {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

int main()
{
    cin >> s >> t;
    m = s.size();
    n = t.size();
    func(m, n);
    string ans = "";
    while (m > 0 && n > 0)
    {
        if (s[m - 1] == t[n - 1])
        {
            ans += s[m - 1];
            m--;
            n--;
        }
        else
        {
            //cout << dp[m-1][n] << " " << dp[m][n-1] << endl;
            if (dp[m - 1][n] > dp[m][n - 1]) m--;
            else n--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

