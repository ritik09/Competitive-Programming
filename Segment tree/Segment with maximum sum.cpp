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


struct item
{
    ll seg,pre,suff,sum;
};
struct segtree
{
    ll size=1;
    vector<item>values;
    void init(ll n)
    {
        while(size<n)
        {
            size*=2;
        }
        values.resize(2*size);
    }
    item merge(item a ,item b)
    {
        return {
            max(a.seg,max(b.seg,a.suff+b.pre)),
            max(a.pre,a.sum+b.pre),
            max(b.suff,b.sum+a.suff),
            a.sum+b.sum
        };
    }
    item single(int v)
    {
        if(v>0)
        {
            return {v,v,v,v};
        }
        else
        {
            return {0,0,0,v};
        }
    }
    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            values[x]=single(v);
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
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(ll i,ll v)
    {
        set(i,v,0,0,size);
    }
    item cal(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(l>=rx || r<=lx)
        return {0,0,0,0};
        if(lx>=l && rx<=r)
        return values[x];
        ll m=(lx+rx)/2;
        item s1=cal(l,r,2*x+1,lx,m);
        item s2=cal(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item cal(ll l,ll r)
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
    cout<<st.cal(0,n).seg<<"\n";
    while(m--)
    {
        
        ll i,v;cin>>i>>v;
        st.set(i,v);
        auto x=st.cal(0,n);
        cout<<x.seg<<"\n";
    
    }
}
