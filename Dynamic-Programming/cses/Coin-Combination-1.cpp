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
ll dp[N];
 
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
 
ll solve(ll i,ll n,ll x)
{
    dp[0] = 1;
    for(ll i = 1; i <= x ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            if(c[j]<=i)
            {
                dp[i] = add(dp[i],dp[i-c[j]]);
            }
        }
    } 
    return dp[x];
}
int main()
{
    fastIO
    ll n , x; cin>>n>>x;
    for(ll i = 0 ; i < n ; i++)
    cin >> c[i];
    cout<<solve(0,n,x);
    
}