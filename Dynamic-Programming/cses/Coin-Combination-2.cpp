#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define mp make_pair
#define inf LLONG_MAX
#define MIN LLONG_MIN
#define mod 1000000007
#define N 1000002
ll c[101];
 
 
inline ll add(ll x, ll y){ x += y; if(x >= mod) x -= mod; return x;}
 
ll solve(ll n,ll x ,vector<vector<ll> >&dp)
{
    ll op1,op2;
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 0 ; j <= x ; j++)
        {   
            if(j==0)
            dp[i][j] = 1;
            else
            {
                if(j>=c[i])
                {
                    op1 = dp[i][j-c[i]];
                }
                else
                op1 = 0;
                if(i==1)
                op2=0;
                else
                op2 = dp[i-1][j];
                dp[i][j] = add(op1,op2);
            }
        }
    } 
    return dp[n][x];
}
int main()
{
    fastIO
    ll n , x; cin>>n>>x;
    vector<vector<ll> >dp(n+1,vector<ll>(x+1,0));
    for(ll i = 1 ; i <= n ; i++)
    cin >> c[i];
    cout<<solve(n,x,dp);
}