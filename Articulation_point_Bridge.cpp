#include <bits/stdc++.h>
using namespace std;

bool articulation_point[1000],visited[1000];
int low[1000],discovery_time[1000],t=0;
vector<int>v[1000];
vector<pair<int,int> >bridges;
void FindArticulationPoint(int u,int par)
{
    t++;
    low[u]=discovery_time[u]=t;
    visited[u]=true;
    int no_of_children=0;
    for(auto x:v[u])
    {
        if(x==par) continue;
        if(visited[x]==true) ///This is a backedge
        {
            low[u]=min(low[u],discovery_time[x]);
        }
        else                ///This is a tree edge
        {
            FindArticulationPoint(x,u);
            low[u]=min(low[u],low[x]);
            if(discovery_time[u]<=low[x] && par!=-1)
            {
                articulation_point[u]=true;     ///articulation point
            }
            if(discovery_time[u]<low[x])
            {
                bridges.push_back({u,x});       ///bridges
            }
            no_of_children++;
        }
    }
    if(no_of_children>1 && par==-1)
        {
            articulation_point[u]=true;
        }
}

int main()
{
    int i,node,edge,a,b,source=1;
    cin >> node >> edge;
    for(i=0;i<edge;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(articulation_point,false,sizeof(articulation_point));
    for(i=1;i<=node;i++)
    {
        if(visited[i]==0) FindArticulationPoint(i,-1);
    }
    for(i=1;i<=node;i++)
    {
        if(articulation_point[i])
        {
            cout << i << " yes" << endl;
        }
    }
    for(auto x:bridges)
    {
        cout << x.first << " " << x.second << endl;
    }
}
