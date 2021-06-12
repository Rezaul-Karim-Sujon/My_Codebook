#include <bits/stdc++.h>
using namespace std;

int indegree[200000];
vector<int>v[200000];
int visited[200000];

int main()
{
    int node,edge,i,a,b,counter=0;
    cin >> node >> edge;
    vector<int>ans;
    for(i=0;i<edge;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    queue<int>Q;
    for(i=1;i<=node;i++)
    {
        if(indegree[i]==0)
        {
            Q.push(i);
           // cout << i << endl;
        }
    }
    counter=node;
    while(!Q.empty())
    {
        int n=Q.front();

        //visited[n]=1;
        ans.push_back(n);
        node--;
        Q.pop();
        for(i=0;i<v[n].size();i++)
        {
            indegree[v[n][i]]--;
            if(indegree[v[n][i]]==0)
            {
                Q.push(v[n][i]);
            }
        }
    }
    if(node)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        for(i=0;i<ans.size();i++)
        {
            cout << ans[i] << " " << endl;
        }
    }
}
