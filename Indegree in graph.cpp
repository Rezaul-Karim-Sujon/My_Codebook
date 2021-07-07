#include <bits/stdc++.h>
using namespace std;

int indegree[200000];
vector<int>v[200000];
int main()
{
    int node,edge,i,a,b;
    cin >> node >> edge;
    for(i=0;i<edge;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    for(i=1;i<=node;i++)
    {
        cout << indegree[i] << endl;
    }
}
