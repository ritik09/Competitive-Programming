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
ll binary_lifting(ll a,ll b,ll n)
{
    if(level[a] > level[b])
    swap(a,b);
    ll d = level[b] - level[a];
    while(d)
    {
        ll i = log2(d);
        b = lca[b][i];
        d-=(1<<i);
    }
    if(a==b)
    return a;
    // cout<<lca[a][0]<<" "<<lca[b][0]<<" ";
    for(ll i = log2(n) ; i >= 0 ;i--)
    {
        if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[b][0];
}
int main()
{
    fastIO
    ll n , q ;cin >> n >> q;
    for(ll i = 1 ; i <= n-1 ; i++)
    {   
        ll x ; cin>>x;
        v[i+1].pb(x);
        v[x].pb(i+1);
    }
    memset(lca,-1,sizeof(lca));
    dfs(1,-1,0);
    fill(n);
    while(q--)
    {
        ll a , b ; cin>>a>>b;
        ll ans = binary_lifting(a,b,n);
        cout<<ans<<"\n";
    }
   
}