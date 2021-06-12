#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    string s, t;
    cin >> s;
    int m, k, i, j, n;
    t = s;
    reverse(t.begin(), t.end());
    m = s.size();
    n = t.size();
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            if(i==j) dp[i][j]=1;
//            else dp[i][j]=0;
//        }
//    }
//    for(k=2;k<=n;k++)
//    {
//        for(i=0;i<n-k+1;i++)
//        {
//            j=i+k-1;
//            if(s[i]==s[j] && k==2) dp[i][j]=2;
//            else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
//            else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
//        }
//    }
//    cout << dp[0][n-1] << endl;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int index = dp[m][n];
    string lcs(index + 1, '\0');
    i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            lcs[index - 1] = s[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    cout << dp[m][n] << " " << lcs << endl;
}
