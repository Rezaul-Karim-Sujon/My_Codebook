#include <bits/stdc++.h>
using namespace std;

int BIT[1000],arr[1000],n,q,a,i,BIT2[1000];
void add(int type,int x,int delta)
{
    if(type==1)
    {
        while(x<=n)
        {
            BIT[x]+=delta;
            x += x & (-x);
        }
    }
    else
    {
        while(x<=n)
        {
            BIT2[x]+=delta;
            x += x & (-x);
        }
    }
}
void range_add(int l,int r,int x)
{
    add(1,l,x);
    add(1,r+1,-x);
    add(2,l,x*(l-1));
    add(2,r+1, -x*r);
}
int sum(int type,int x)
{
    int total=0;
    if(type==1)
    {
        while(x>0)
        {
            total+=BIT[x];
            x -= x & (-x);
        }
    }
    else
    {
        while(x>0)
        {
            total+=BIT2[x];
            x -= x & (-x);
        }
    }
    return total;
}
int prefix_sum(int x)
{
    int a=sum(1,x)*x;
    int b=sum(2,x);
    return a-b;
}
int range_sum(int l,int r)
{
    int a=prefix_sum(r)-prefix_sum(l-1);
    return a;
}
int main()
{
    cin >> n >> q; ///size of array and query number
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
        add(1,i,arr[i]);
    }
    while(q--)
    {
        string s;
        cin >> s;
        if(s=="sum")
        {
            cin >> a;
            cout << sum(1,a) << endl; ///cumalative sum
        }
        else
        {
            cin >> i >> a;
            a-=arr[i]; /// difference between original number
            add(1,i,a); /// update the original number
        }
    }
}
