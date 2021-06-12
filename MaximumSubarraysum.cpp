#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,i,sum=0,best=0;
    cin >> n;
    vector<int>v;
    for(i=1;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for(i=0;i<v.size();i++)
    {
        sum=max(v[i],sum+v[i]);
        best=max(best,sum);
    }
    cout << best << endl;
}


///UVA 507-Jill Rides Again
