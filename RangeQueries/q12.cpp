/* * * * * * * * * * * **
*                      *
*      saurabh8522     *
*     I will handle    *
*          IT.         *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
vector<ll>v,b;
vector< vector<ll> >seg;
const ll INF=1e9;
void build(int node,int l,int r){
    if(l==r){
        seg[node].pb(b[l]);
        return ;
    }
    else{
        int mid=(l+r)>>1;
        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);
        merge(all(seg[2*node+1]),all(seg[2*node+2]),inserter(seg[node],seg[node].begin()));
        return ;
    }
}
int find(int node,int l,int r,int ql,int qr,int x){
    // vector<ll> le,rt,res;
    if(l>qr||r<ql){
        return 0;
    }
    if(l>=ql&&r<=qr){
        // vector<ll>v=seg[node];
        int le=0,rt=seg[node].size()-1,ans=seg[node].size();
        while(le<=rt){
            int m=(le+rt)>>1;
            if(seg[node][m]>x){
                ans=m;
                rt=m-1;
            }
            else{
                le=m+1;
            }
        }
        return seg[node].size()-ans;
    }
    int mid=(l+r)>>1;
    // le=find(2*node+1,l,mid,ql,qr);
    // rt=find(2*node+2,mid+1,r,ql,qr);
    return find(2*node+1,l,mid,ql,qr,x)+find(2*node+2,mid+1,r,ql,qr,x);
    // return res;
}
int  main(){
    FastRead;
    int t=1;
    // cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        v.resize(n);
        b.resize(n,INF);
        seg.resize(3*n,vector<ll>());
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        mp[v[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            if(mp.find(v[i])!=mp.end()){
                b[i]=mp[v[i]];
            }
            mp[v[i]]=i;
        }
        build(0,0,n-1);
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<find(0,0,n-1,l,r,r)<<endl;
        }
    }
}