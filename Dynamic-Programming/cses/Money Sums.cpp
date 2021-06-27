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
#define N 100002
ll dp[101][N];
 
int main()
{
    fastIO
    ll n ; cin>>n;
    ll a[n];
    for(ll i = 0; i < n ; i++)
    cin >> a[i];
    set<int>s;
    dp[0][a[0]] = 1;
    s.insert(a[0]);
    for(ll i = 1 ; i < n ;i++)
    {
        dp[i][a[i]] = 1;
        s.insert(a[i]);
        for(int j = 1 ; j < N ; j++)
        {
            if(dp[i-1][j] || (j>a[i] && dp[i-1][j-a[i]]))
            {
                dp[i][j] = 1;
                s.insert(j);
            }
        }
    }
    cout<<(ll)s.size()<<"\n";
    for(auto i:s)
    cout<<i<<" ";
}