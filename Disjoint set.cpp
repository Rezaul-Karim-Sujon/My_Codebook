#include <bits/stdc++.h>
using namespace std;

int arr[1006],size[1006];

void initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        arr[i]=i;
        size[i]=1;
    }
}

int root(int x)
{
    while(arr[x]!=x)
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return x;
}

void weighted_union(int a, int b)///Union by size
{
    int rootA=root(a);
    int rootB=root(b);
    if(rootA!=rootB)
    {
        if(size[rootA]<size[rootB])
        {
            swap(rootA,rootB);
        }
        arr[rootB]=rootA;
        size[rootA]+=size[rootB];
    }
}

int main(int argc, char const *argv[])
{
    int n,m,i,a,b;
    cin >> n >> m;
    initialize(n);
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        weighted_union(a,b);
        std::vector<int> v;
        for(int j=1; j<=n; j++)
        {
            int fo=size[j];
            v.push_back(fo);
        }
        //sort(v.begin(),v.end());
        for(int j=0; j<v.size(); j++)
        {
            if(j==v.size()-1)
            {
                cout << v[j] << endl;
            }
            else
                std::cout << v[j] << " ";
        }

    }
    cin >> a;
    cout << size[root(a)] << endl;
    return 0;
}
