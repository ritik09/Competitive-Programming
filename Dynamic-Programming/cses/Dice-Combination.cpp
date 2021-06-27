#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pl pair<ll, ll>
#define vl vector<ll>
#define mp make_pair
#define mod 1000000007
#define N 1000001
 
 
int main()
{
    fastIO
    ll n;cin>>n;
    ll dp[n+1]={0};
    dp[0]=1;
    ll sum=0;
    for(ll i=1;i<n+1;i++)
    {
        for(ll j=1;j<=6 && i-j>=0 ;j++)
        {
            dp[i]+=(dp[i-j])%mod;
        }
    }
    cout<<dp[n]%mod<<"\n";
}   