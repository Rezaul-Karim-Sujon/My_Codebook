#include <bits/stdc++.h>
using namespace std;
int dp[200],last[256];
int main()
{
    string s;
    cin >> s;
    memset(last,-1,sizeof(last));
    dp[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        dp[i]=2*dp[i-1];
        if(last[s[i-1]]!=-1)
        {
            dp[i]-=dp[last[s[i-1]]];
        }
        last[s[i-1]]=i-1;
        cout << dp[i] << endl;
    }
    cout << dp[s.size()] << endl;
}
/*
abcd
abc abd acd bcd
ab ac ad bc bd cd
a b c d
*/
