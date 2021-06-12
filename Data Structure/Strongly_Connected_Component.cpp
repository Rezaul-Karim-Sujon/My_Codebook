#include <bits/stdc++.h>
using namespace std;

int color[100005],visited[100005],mark=0;
stack<int>stk;
vector<int>v[100005],rev_v[100005],components[100005];

void take_vertices(int edges)
{
    int i,a,b;
    for(i=0;i<edges;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        rev_v[b].push_back(a);
    }
}

void dfs_sorting_nodes(int root)
{
    color[root]=1;
    for(int x:v[root])
    {
        if(color[x]==0)
        {
            dfs_sorting_nodes(x);
        }
    }
    stk.push(root);
}

void final_dfs(int root)
{
    components[mark].push_back(root);
    visited[root]=1;
    for(int x:rev_v[root])
    {
        if(visited[x]==0)
        {
            final_dfs(x);
        }
    }
}

void find_strongly_connected_component(int node)
{
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    int i;
    mark=0;
    for(i=1;i<=node;i++)
    {
        if(color[i]==0)
        {
            dfs_sorting_nodes(i);
        }
    }
    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();
        if(visited[u]==0)
        {
            mark++;
            final_dfs(u);
        }
    }
}

void show_strongly_connected_components()
{
    for(int i=1;i<=mark;i++)
    {
        cout << i << "-> ";
        for(int x:components[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int node,edges;
    cin >> node >> edges;
    take_vertices(edges);
    find_strongly_connected_component(node);
    show_strongly_connected_components();
}
