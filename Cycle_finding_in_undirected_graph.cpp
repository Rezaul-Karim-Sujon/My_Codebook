#include <bits/stdc++.h>
using namespace std;
int parent[3001], visited[3001], start, finish, dist[3001];
vector<int>v[3001];
void take_vertices(int edges) {
  int i, a, b;
  for (int i = 1; i <= edges; ++i) {
    cin >> a >> b;
    parent[i] = -1;
    v[a].push_back(b);
    v[b].push_back(a);
  }
}
void dfs(int root,int par)
{
    visited[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
        int x=v[root][i];
        if(x==par) continue;
        if(visited[x]==0)
        {
            parent[x]=root;
            dfs(x,parent[x]);
        }
        else
        {
            start=x;
            finish=root;
        }
    }
}
int root(int r)
{
   cout << r << "->";
    if(finish!=parent[r])
    {
        parent[r]=root(parent[r]);
    }
    return parent[r];
}
int main(){
  int n, a, b,i;
  cin >> n;
  take_vertices(n);
  dfs(1,parent[1]);
  memset(dist, -1, sizeof(dist));
  memset(visited, 0, sizeof(visited));
  a=root(start);
  cout << finish << endl;
}
