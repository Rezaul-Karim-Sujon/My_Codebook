#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[200000];
void check_trie(int root,int level)
{
    int i,x;
    for(i=0;i<v[root].size();i++)
    {
        check_trie(v[root][i].first,level+1);
        cout << root << " " << v[root][i].first << " " << v[root][i].second << endl;
    }
}
int main()
{
    int n,k,i,new_node=2,node,cha_value,j;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        node=1;
        /// creating trie
        for(i=0; i<s.size(); i++)
        {
            cha_value=s[i];
            bool pai_nai=true;
            for(j=0; j<v[node].size(); j++)
            {
                if(v[node][j].second==cha_value)
                {
                    node=v[node][j].first;
                    pai_nai=false;
                    break;
                }
            }
            if(pai_nai)
            {
                v[node].push_back(make_pair(new_node,cha_value));
                node=new_node;
                new_node++;
            }
        }
    }
    check_trie(1,0); /// checking whole trie
}
