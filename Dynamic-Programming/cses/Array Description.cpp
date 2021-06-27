#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<int>
#define mp make_pair
#define inf LLONG_MAX
#define MIN LLONG_MIN
#define mod 1000000007
#define N 1000001
 
 
inline ll add(ll x, ll y){ x += y; if(x >= mod) x -= mod; return x;}
int main()
{
    fastIO
    ll n , m ;cin>>n>>m;
    ll a[n];
    for(ll i = 0 ; i  < n ; i++)
    cin >> a[i];
    vector<vector<ll> >dp(n,vector<ll>(m+1,0));
    if(a[0])
    dp[0][a[0]] = 1;
    else
    {
        fill(dp[0].begin(),dp[0].end(),1);
    }
    for(ll i = 1 ; i < n ; i++)
    {
        if(!a[i])
        {
            for(int j = 1; j <= m ; j++)
            {
                for(ll k = j-1 ; k <= j+1 ; k++)
                {
                    if(k>=1 && k<=m)
                    dp[i][j] = add(dp[i][j],dp[i-1][k]);
                }
            }
        }
        else
        {
            for(ll k = a[i]-1 ; k <= a[i]+1 ; k++)
            {
                if(k>=1 && k<=m)
                dp[i][a[i]] = add(dp[i][a[i]],dp[i-1][k]);
            }
        }
    }
    ll ans=0;
    for(ll i = 1 ;  i <= m ; i++)
    ans=add(ans,dp[n-1][i]);
    cout<<ans<<"\n";
}