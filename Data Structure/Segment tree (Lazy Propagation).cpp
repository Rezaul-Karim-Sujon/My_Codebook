#include <bits/stdc++.h>
using namespace std;

int arr[1000],tree[3003],lazy[3003];

void initializ(int node,int start,int finish)
{
    if(start==finish)
    {
        tree[node]=arr[start];
        return ;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(start+finish)/2;
    initializ(left,start,mid);
    initializ(right,mid+1,finish);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int i,int j,int new_value)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node]+=(e-b+1)*new_value;
        lazy[node]+=new_value;
        return;
    }
    int left=node*2;
    int right=left +1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,new_value);
    update(right,mid+1,e,i,j,new_value);
    tree[node]=tree[left]+tree[right]+(e-b+1)*lazy[node];
}
int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node]+carry*(e-b+1);
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j,carry+lazy[node]);
    int p2=query(right,mid+1,e,i,j,carry+lazy[node]);
    return p1+p2;
}
int main()
{
    int i,n,pat,a,b,value,q;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    initializ(1,1,n);
    cin >> q;
    while(q--)
    {
        cin >> pat;
        if(pat==1)
        {
            cin >> a >> b >> value;
            update(1,1,n,a,b,value);
        }
        else if(pat==2)
        {
            cin >> a >> b;
            cout << query(1,1,n,a,b,0) << endl;
        }
    }
    return 0;
}
