#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vl vector<ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define N 100005

 
struct segtree
{
    ll size=1;
    vector<ll>values;
    void init(ll n)
    {
        while(size<n)
        {
            size*=2;
        }
        values.assign(2*size,0);
    }
    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            values[x]=v;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else
        {
            set(i,v,2*x+2,m,rx);
        }
        values[x]=min(values[2*x+1],values[2*x+2]);
    }
    void set(ll i,ll v)
    {
        set(i,v,0,0,size);
    }
    ll cal(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(l>=rx || r<=lx)
        return INT_MAX;
        if(lx>=l && rx<=r)
        return values[x];
        ll m=(lx+rx)/2;
        ll s1=cal(l,r,2*x+1,lx,m);
        ll s2=cal(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    ll cal(ll l,ll r)
    {
        return cal(l,r,0,0,size);
    }
};
int main()
{
    fastIO
    ll n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        ll v;cin>>v;
        st.set(i,v);
    }
    while(m--)
    {
        ll op;cin>>op;
        if(op==1)
        {
            ll i,v;cin>>i>>v;
            st.set(i,v);
        }
        else
        {
            ll l,r;cin>>l>>r;
            cout<<st.cal(l,r)<<"\n";
        }
    }
}
