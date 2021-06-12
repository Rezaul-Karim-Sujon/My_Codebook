#define nl              "\n"
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
#define SIZE(a)           (int)a.size()
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define ff              first
#define ss              second
#define sq(a)           ((a)*(a))
#define For(i,a,b)      for(i=a;i<=b;i++)
#define Rof(i,a,b)      for(i=a;i>=b;i--)
#define Rep(i,b)        for(i=0;i<b;i++)
#define MOD             1000000007
#define PI              acos(-1.0)
#define eps             1e-9
#define Linf            2e18
#define inf             1<<30
#define MX5             100005
#define MX6             1000006
#define GCD(a,b)	__gcd(a,b)
#define Abs(a)		abs(a)
#define input(a,b)	scanf("%lld%lld",&a,&b)
#define in1(a)		scanf("%lld",&a)
#define output(a)	printf("%lld",a);
#define mem(a)          memset(a,-1,sizeof(a))
#define clr(a)          memset(a,0,sizeof a)
#define mk              make_pair
#define pLL             pair<ll,ll>
#define ff              first
#define ss              second
#define invcos(a)	(acos(a)*(180/3.14159265))
#define pip		printf("pip")
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
///8direction ->        int del_x[]={-1,0,1,0,1,-1,-1,1},del_y[]={0,1,0,-1,-1,-1,1,1};


#include <bits/stdc++.h>
using namespace std;

ll n,m,visited[200][200];
ll del_x[]= {-1,0,1,0},del_y[]= {0,1,0,-1};
char s[200][200];
//ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
//ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
bool check(ll x,ll y)
{
    if(x>=1 && x<=m && y>=1 && y<=n)
    {
        return true;
    }
    return false;
}

void dfs(ll a,ll b)
{

    for(ll i=0; i<4; i++)
    {
        ll x=del_x[i]+a;
        ll y=del_y[i]+b;
        if(check(x,y)==true && visited[x][y]==0 && s[x][y]=='.')
        {
            visited[x][y]=1;
            dfs(x,y);
        }
    }
}

int main()
{
    ll i,j,x,y;
    input(n,m);
    For(i,1,m)
    {
        For(j,1,n)
        {
            cin >> s[i][j];
            if(s[i][j]=='@')
            {
                x=i;
                y=j;
                s[x][y]='.';
            }
        }
    }
    dfs(x,y);
    For(i,1,m)
    {
        For(j,1,n)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }
}
