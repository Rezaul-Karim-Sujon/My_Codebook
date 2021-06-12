#include <bits/stdc++.h>
using namespace std;

int arr[1000],tree[3003];

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
int query(int node,int start,int finish,int i,int j)
{
    if(i>finish || j<start)
        return 0;
    if(start>=i && finish<=j)
        return tree[node];
    int left,right,mid,p1,p2;
    left=node*2;
    right=left+1;
    mid=(start+finish)/2;
    p1=query(left,start,mid,i,j);
    p2=query(right,mid+1,finish,i,j);
    return p1+p2;
}
void update(int node,int start,int finish,int i,int newvalue) ///  update a value like a=5 then a=3
{
    if(i>finish || i<start) return;
    if(start>=i && finish<=i)
    {
        tree[node]=newvalue;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=left+1;
    mid=(start+finish)/2;
    update(left,start,mid,i,newvalue);
    update(right,mid+1,finish,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

void add(int node,int start,int finish,int i,int newvalue) /// Add new value to a index like a=5+new_value
{
    if(i>finish || i<start) return;
    if(start>=i && finish<=i)
    {
        tree[node]+=newvalue;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=left+1;
    mid=(start+finish)/2;
    add(left,start,mid,i,newvalue);
    add(right,mid+1,finish,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int i,n,pat,a,b,value,q;
    cin >> n;
    for(i=1;i<=n;i++)
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
            cin >> a >> value;
            update(1,1,n,a,value);
        }
        else if(pat==2)
        {
            cin >> a >> b;
            cout << query(1,1,n,a,b) << endl;
        }
        else
        {
            cin >> a >> value;
            add(1,1,n,a,value);
        }
    }
    return 0;
}
