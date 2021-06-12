#define nl              "\n"
#define ll              long long


#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


int main()
{
    ll a,counter=-1;
    vector<ll>v;
    while(cin >> a && !cin.eof())
    {
        vector<ll>::iterator it=lower_bound(v.begin(),v.end(),a);
        //cout << a << " " << it-v.begin() << endl;
        if(it==v.end()) /// if a is the last element than push in the vector
        {
            v.push_back(a);
            //cout << a << endl;
        }
        else /// if a is not the last element than replace the last value with a
        {
            *it=a;
            //cout << *it << endl;
        }
    }
    cout << v.size() << endl << "-" << endl;
    for(auto x:v)
    {
        cout << x << endl;
    }
}
