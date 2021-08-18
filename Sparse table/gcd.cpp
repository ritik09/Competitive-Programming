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
#define mod 1000000007
#define N 200002
vector<vl>table(N,vector<ll>(21));

ll query(ll l, ll r)
{
    ll len = r - l + 1;
    ll k = log2(len);
    return __gcd(table[l][k], table[r-(1<<k)+1][k]);
}
bool possible(ll mid, ll n)
{
    for(ll i = 1; i+mid-1 <= n; i++)
    {
        if(query(i, i+mid-1) >= 2)
        return true;
    }
    return false;
}
int main()
{
    fastIO
    ll t;cin>>t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll>a(n),b(n);
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        n--;
        for(ll i = 1; i <= n; i++)
        b[i] = abs(a[i] - a[i-1]);

        //sparse table
        for (ll  i = 1; i <= n; i++)
            table[i][0] = b[i];

        for (ll j = 1; j <= 20; j++)
        {
            for (ll i = 1; i + (1<<j) <= n + 1; i++)
            {
                table[i][j] = __gcd(table[i][j - 1], table[i + (1<<(j - 1))][j - 1]);
            }
        }
        ll l = 1, r = n, ans = 0;
        while(l <= r)
        {
            ll mid = (l + r) / 2;
            if(possible(mid, n))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            r = mid - 1;
        }
        cout<<ans + 1<<"\n";
    }
}