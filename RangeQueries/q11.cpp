/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
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
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
struct node{
	ll sum,psum,ssum,msum;
};
vector<node>seg;
vector<ll>v;
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node].sum=seg[node].ssum=seg[node].psum=seg[node].msum=v[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	seg[node].sum=seg[2*node+1].sum+seg[2*node+2].sum;
	seg[node].psum=max(seg[2*node+1].psum,seg[2*node+1].sum+seg[2*node+2].psum);
	seg[node].ssum=max(seg[2*node+2].ssum,seg[2*node+2].sum+seg[2*node+1].ssum);
	seg[node].msum=max(seg[2*node+2].msum,max(seg[2*node+1].msum,seg[2*node+1].ssum+seg[2*node+2].psum));
	return ;
}
void update(ll node,ll l,ll r,ll idx,ll val){
	if(l==r){
		seg[node].sum=seg[node].ssum=seg[node].psum=seg[node].msum=val;
		return;
	}
	else{
		ll mid=(l+r)>>1;
		if(idx>=l&&idx<=mid){
			update(2*node+1,l,mid,idx,val);
		}
		else{
			update(2*node+2,mid+1,r,idx,val);
		}
		seg[node].sum=seg[2*node+1].sum+seg[2*node+2].sum;
		seg[node].psum=max(seg[2*node+1].psum,seg[2*node+1].sum+seg[2*node+2].psum);
		seg[node].ssum=max(seg[2*node+2].ssum,seg[2*node+2].sum+seg[2*node+1].ssum);
		seg[node].msum=max(seg[2*node+2].msum,max(seg[2*node+1].msum,seg[2*node+1].ssum+seg[2*node+2].psum));
		return ;
	}
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		v.resize(n);
		seg.resize(4*n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,0,n-1);
		for(int i=0;i<m;i++){
			ll k,x;
			cin>>k>>x;
			k--;
			update(0,0,n-1,k,x);
			cout<<seg[0].msum<<endl;
		}
	}
}