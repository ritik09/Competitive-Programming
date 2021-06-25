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
    vector<ll>sums;
    void init(ll n)
    {
        while(size<n)
        {
            size*=2;
        }
        sums.assign(2*size,0);
    }
    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            sums[x]=v;
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
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void set(ll i,ll v)
    {
        set(i,v,0,0,size);
    }
    ll sum(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(l>=rx || r<=lx)
        return 0;
        if(lx>=l && rx<=r)
        return sums[x];
        ll m=(lx+rx)/2;
        ll s1=sum(l,r,2*x+1,lx,m);
        ll s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    ll sum(ll l,ll r)
    {
        return sum(l,r,0,0,size);
    }
    ll find(ll k,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        return lx;
        ll mid=(lx+rx)/2;
        ll sl=sums[2*x+1];
        if(k<sl)
        {
            return find(k,2*x+1,lx,mid);
        }
        else
        {
            return find(k-sl,2*x+2,mid,rx);
        }
        
    }
    ll find(ll k)
    {
        return find(k,0,0,size);
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
        cin>>a[i];
        st.set(i,a[i]);
    }
    while(m--)
    {
        ll op;cin>>op;
        if(op==1)
        {
            ll i;cin>>i;
            a[i]=1-a[i];
            st.set(i,a[i]);
        }
        else
        {
            ll k;cin>>k;
            cout<<st.find(k)<<"\n";
        }
    }
}
