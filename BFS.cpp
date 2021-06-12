#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v[100];
    int nodes[100][100],i,j,a,b,node,edge,n,visited[100],label[100];
    cout << "Enter the number of node:- ";
    cin >> node;
    cout <<  endl << "Enter the number of edge:- ";
    cin >> edge;
    memset(visited,0,sizeof(visited));
    memset(label,0,sizeof(label));
    cout << "Enter the paths" << endl;
    for(i=1; i<=edge; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int source=1,destination;
    cin >> destination;
    visited[source]=1;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty())
    {
        int n=Q.front();
        //cout << n << " ";
        if(n==destination)
        {
            cout << label[n] << endl;
            return 0;
        }
        Q.pop();
        for(i=0; i<v[n].size(); i++)
        {
            if(visited[v[n][i]]==0)
            {
                label[v[n][i]]=label[n]+1;
                visited[v[n][i]]=1;
                Q.push(v[n][i]);
            }
        }
    }
}

