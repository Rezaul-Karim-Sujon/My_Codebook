#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int,int> >S;
    int n,a,i,maxi=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        if(S.empty())
        {
            S.push(make_pair(a,i));
        }
        else
        {
            int fe=S.top().first;
            if(a>=fe)
            {
                S.push(make_pair(a,i));
            }
            else
            {
                int value,index,prev;
                while(!S.empty())
                {
                    value=S.top().first;
                    index=S.top().second;
                    if(index<a)
                        break;
                    S.pop();
                    int calc=(i-index)*value;
                    maxi=max(calc,maxi);
                    prev=index;
                }
                S.push(make_pair(a,prev));
            }
        }
    }
    while(!S.empty())
    {
        int value=S.top().first;
        int index=S.top().second;
        S.pop();
        int calc=(n-index)*value;
        maxi=max(calc,maxi);
    }
    cout << maxi << endl;
}
