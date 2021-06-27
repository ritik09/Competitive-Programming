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
#define N 1000002
ll level[N],vis[N];
 
void bfs(ll n)
{
    queue<ll>q;
    q.push(n);
    vis[n]=1;
    while(!q.empty())
    {
        ll x = q.front();
        ll y = x;
        q.pop();
        while(y)
        {
            ll d = y%10;
            if(!vis[x-d] && (x-d)>=0)
            {
                q.push(x-d);
                level[(x-d)] = level[x]+1;
                vis[x-d]=1;
            }
            y/=10;
        }
    }
}
int main()
{
    fastIO
    ll n ;cin>>n;
    bfs(n);
    cout<<level[0]<<"\n";
}