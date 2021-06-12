#define     MOD     1000000007
#include <bits/stdc++.h>
using namespace std;
long long int n,c[2][2],z[2][2],ans[2][2];
void mul(long long int a[2][2],long long int b[2][2])
{
    long long int i,j,k;
    memset(c,0,sizeof(c));
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
}
void solve(long long int n)
{
    long long int i,j;
    ans[0][0]=ans[1][1]=1;
    ans[0][1]=ans[1][0]=0;
    while(n>0)
    {
        if(n&1)
        {
            mul(ans,z);
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                {
                    ans[i][j]=c[i][j];
                }
            }
            n--;
        }
        else
        {
            mul(z,z);
            for(i=0;i<2;i++)
            {
                for(j=0;j<2;j++)
                {
                    z[i][j]=c[i][j];
                }
            }
            n>>=1;
        }
    }
}
int main()
{
    long long int a,b;
    cin >> a >> b >> n;
    z[0][0]=z[0][1]=z[1][0]=1;
    z[1][1]=0;
    if(n>=2)
    {
        solve(n-1);
        cout << (ans[0][0]*b+ans[0][1]*a)%MOD << endl;
    }
    else
    {
        cout << b << endl;
    }
}
