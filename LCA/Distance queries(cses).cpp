#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define mp make_pair
#define inf LLONG_MAX
#define MIN LLONG_MIN
#define mod 1000000007
#define N 200002
const ll m = log2(N);
vector<vl>v(N);
ll lca[N][21];
ll level[N];
ll cnt;
 
void dfs(ll node,ll pa,ll lev)
{
    lca[node][0] = pa;
    level[node] = lev;
    for(auto i:v[node])
    {
        if(i!=pa)
        dfs(i,node,lev+1);
    }
}
void fill(ll n)
{
    for(ll j = 1 ; j <= log2(n) ;j++)
    {
        for(ll i = 2 ; i <= n ;i++)
        {
            if(lca[i][j-1]!=-1)
            {
                ll par = lca[i][j-1];
                lca[i][j] = lca[par][j-1];
            }
        }
    }
}
void binary_lifting(ll a,ll b,ll n)
{
    if(level[a] > level[b])
    swap(a,b);
    ll d = level[b] - level[a];
    while(d)
    {
        ll i = log2(d);
        b = lca[b][i];
        d-=(1<<i);
        cnt+=(1<<i);
    }
    if(a==b)
    return;
    for(ll i = log2(n) ; i >= 0 ;i--)
    {
        if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
        {
            a = lca[a][i];
            b = lca[b][i];
            cnt+=2*(1<<i); 
        }
    }
    cnt+=2;
}
int main()
{
    fastIO
    ll n , q ;cin >> n >> q;
    for(ll i = 1 ; i <= n-1 ; i++)
    {   
        ll x,y ; cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    memset(lca,-1,sizeof(lca));
    dfs(1,-1,0);
    fill(n);
    // for(ll i = 1 ; i <= n ;i++)
    // {
    //     for(ll j = 0 ; j <= 5; j++)
    //     cout<<lca[i][j]<<" ";
    //     cout<<"\n";
    // }
    while(q--)
    {
        ll a , b ; cin>>a>>b;
        cnt = 0;
        binary_lifting(a,b,n);
        cout<<cnt<<"\n";
    }
}