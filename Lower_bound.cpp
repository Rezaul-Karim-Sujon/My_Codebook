#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int n,i,q,a;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cin >> q;
    vector<int>::iterator it;
    for(i=0;i<q;i++)
    {
        cin >> a;
        it=lower_bound(v.begin(),v.end(),a);
        cout << a << "->" << (it-v.begin()) << endl;
    }
}
