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
#define N 200002
ll price[1001],pages[1001];
ll x,n;
 
int main()
{
    fastIO
    cin>>n>>x;
    for(ll i = 1 ;  i <= n ; i++)
    cin>>price[i];
    for(ll i = 1 ; i  <= n ; i++)
    cin>>pages[i];
    vector<vl>dp(n+1,vl(x+1,0));
    ll mx = 0 ;
    for(ll i = 1 ; i < n+1 ; i++)
    {
        for(ll j = 1 ; j < x+1; j++)
        {
            if(dp[i-1][j])
            {
                dp[i][j] = dp[i-1][j];
            }
            if((j-price[i])>=0)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-price[i]] + pages[i]);
            }
            mx = max(mx,dp[i][j]);
        }
    }
    cout<<mx<<"\n";
}