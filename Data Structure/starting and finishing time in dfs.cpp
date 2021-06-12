#define white 0
#define gray -1
#define black 1



#include <bits/stdc++.h>
using namespace std;

int start[100],finish[100],visited[100];
vector<int>v[100];
int node,edge,i,j,a,b,tim=0;

int dfs(int source)
{
    int u=source;
    tim++;
    start[u]=tim;
    visited[u]=gray;
    for(i=0; i<v[u].size(); i++)
    {
        if(visited[v[u][i]]==white)
        {
            dfs(v[u][i]);
        }
    }
    visited[u]=black;
    tim++;
    finish[u]=tim;
    return finish[u];
}

int main()
{
    //cout << white << black << gray;
    cin >> node >> edge;
    for(i=1; i<=edge; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
    }
    int source;
    cin >> source;
    dfs(source);
    for(i=1; i<=node; i++)
    {
        cout << start[i] << " " << finish[i] << endl;
    }
}
