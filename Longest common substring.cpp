/// Time Complexity n*m
/// longest common substring

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,p;
    int i,j,n,m,ans=0;
    cin >> s >> p;
    n=s.size();
    m=p.size();
    int lcs[n+5][m+5];
    memset(lcs,0,sizeof(lcs));
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0 || j==0 || s[i-1]!=p[j-1])
                lcs[i][j]=0;
            else
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                ans=max(ans,lcs[i][j]);
            }
        }
    }
    cout << ans << endl;
}
