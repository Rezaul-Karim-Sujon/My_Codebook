#define mx  100002

#include <bits/stdc++.h>
using namespace std;

int level[mx],sparse_table[mx][22],parent[mx];
vector<int>adg_list[mx];

void dfs(int root,int u,int depth)
{
    parent[u]=root;
    level[u]=depth;
    for(auto x:adg_list[u])
    {
        if(x!=root)
        {
            dfs(u,x,depth+1);
        }
    }
}

void lca_init(int node)
{
    memset(parent,-1,sizeof(parent));
    int i,j;
    for(i=0;i<node;i++)
    {
        sparse_table[i][0]=parent[i];
    }
    for(j=1;(1<<j)<node;j++)
    {
        for(i=0;i<node;i++)
        {
            if(sparse_table[i][j-1]!=-1)
            {
                sparse_table[i][j]=sparse_table[sparse_table[i][j-1]][j-1];
            }
        }
    }
}
int lca_query(int p,int q)
{
    int tmp,log,i;
    if(level[p]<level[q])
    {
        swap(p,q);
    }
    log=1;
    while(1)
    {
        int next=log+1;
        if(1<<next>level[p])
            break;
        log++;
    }

    for(i=log;i>=0;i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            p=sparse_table[p][i];
        }
    }
    if(p==q)
        return q;
    for(i=log;i>=0;i--)
    {
        if(sparse_table[p][i]!=-1 && sparse_table[p][i]!=sparse_table[q][i])
        {
            p=sparse_table[p][i];
            q=sparse_table[q][i];
        }
    }
    return parent[p];
}
int main()
{
    int node_number,edge_number,i,a,b,query,l,r;
    cin >> node_number >> edge_number;
    for(i=0;i<edge_number;i++)
    {
        cin >> a >> b;
        adg_list[a].push_back(b);
        adg_list[b].push_back(a);
    }
    dfs(0,0,0);
    lca_init(node_number);
    cin >> query;
    while(query--)
    {
        cin >> l >> r;
        cout << lca_query(l,r) << endl;
    }
}
