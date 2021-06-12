#include <bits/stdc++.h>
using namespace std;
#define    MAXN     5000006
int phi[MAXN];
void phi_1_to_n(int n)
{
    for(int i=1;i<=n;i++) phi[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
int main()
{
    phi_1_to_n(MAXN);
    int n;
    cin >> n;
    cout << phi[n] << endl;
}
