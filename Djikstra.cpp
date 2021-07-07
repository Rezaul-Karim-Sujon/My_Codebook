#define ll long long int
#define inf 2147483647154869

#include <bits/stdc++.h>
using namespace std;
vector<pair<ll,ll> >v[1000000];
vector<ll>dis(1000000,inf);
ll node,edge,source=1,a,b,i,j,x;
map<ll,ll>path;



int main()
{
    //fill(dis.begin(),dis.end(),inf);
    cin >> node >> edge;
    for(i=1; i<=edge; i++)
    {
        cin >> a >> b >> x;
        v[a].push_back({b,x});
        v[b].push_back({a,x});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > Q;
    dis[source]=0;
    path[source]=-1;
    bool check=false;
    Q.push({dis[source],source});
    while(!Q.empty())
    {
        ll n=Q.top().second;
        cout << n << " " << Q.top().first << endl;
        Q.pop();
        if(n==node)
            check=true;
        for(i=0; i<v[n].size(); i++)
        {
            ll t=v[n][i].first;
            ll len=v[n][i].second;
            if(dis[n]+len<dis[t])
            {
                dis[t]=dis[n]+len;
                path[t]=n;
                Q.push({dis[t],t});
            }
        }
    }
    if(check==false)
    {
        cout << "-1" << endl;
        return 0;
    }
    else
    {
        for(i=1;i<=node;i++)
        {
            cout << dis[i] << " ";
        }
        return 0;
        vector<ll>ans;
        for(i=node; i!=-1; i=path[i])
        {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        for(i=0; i<ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
}
