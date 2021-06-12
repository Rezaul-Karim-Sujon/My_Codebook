#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
    int test,t;
    cin >> test;
    for(t=1;t<=test;t++)
    {
        long long int n,q,a,i,j,k;
    cin >> n >> q;
    k=log2(n+5);
    long long int log[n+5],arr[n+5],sparse_table[n+5][k+1];
    log[1]=0;
    for(i=2;i<=n;i++) log[i]=log[i/2]+1;
    for(i=0;i<n;i++)
    {
        cin >> a;
        sparse_table[i][0]=a;
    }
    for(j=1;j<=k;j++)
    {
        for(i=0;i+(1LL << j)<=n;i++)
        {
            sparse_table[i][j]=min(sparse_table[i][j-1],sparse_table[i+(1LL << (j-1))][j-1]);
        }
    }
    cout << "Case " << t << ":" << endl;
    while(q--)
    {
        cin >> i >> j;
        i--;
        j--;
        k=log[j-i+1];
        cout << min(sparse_table[i][k],sparse_table[j-(1LL<<k) +1][k]) << endl;
    }
    }
}

