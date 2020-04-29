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
vector<ll>v,seg,lazy;
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node]=v[l];
		lazy[node]=0;
		return ;
	}
	ll mid=(l+r)>>1;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	seg[node]=seg[2*node+1]+seg[2*node+2];
	lazy[node]=0;
	return ;
}
void update(ll node,ll l,ll r,ll ql,ll qr,ll val){
	if(lazy[node]!=0){
		seg[node]+=(r-l+1)*lazy[node];
		if(l!=r){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(r<ql||l>qr) return ;
	if(l>=ql&&r<=qr){
		seg[node]+=(r-l+1)*val;
		if(l!=r){
			lazy[2*node+1]+=val;
			lazy[2*node+2]+=val;
		}
		return ;
	}
	ll mid=(l+r)>>1;
	update(2*node+1,l,mid,ql,qr,val);
	update(2*node+2,mid+1,r,ql,qr,val);
	seg[node]=seg[2*node+1]+seg[2*node+2];
	return;
} 
ll sum(ll node,ll l,ll r,ll ql,ll qr){
	if(r<ql||l>qr) return 0;
	if(lazy[node]!=0){
		seg[node]+=(r-l+1)*lazy[node];
		if(l!=r){
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+2]+=lazy[node];
		}
		lazy[node]=0;
		// return seg[node];
	}
	if(l>=ql&&r<=qr){
		return seg[node];
	}
	ll mid=(l+r)>>1;
	return sum(2*node+1,l,mid,ql,qr)+sum(2*node+2,mid+1,r,ql,qr);
}
int  main(){
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		v.resize(n);
		seg.resize(4*n,0);
		lazy.resize(4*n,0);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,0,n-1);
		for(int i=0;i<q;i++){
			ll type;
			cin>>type;
			if(type==1){
				ll l,r,val;
				cin>>l>>r>>val;
				l--;r--;
				update(0,0,n-1,l,r,val);
			}
			else{
				ll idx;
				cin>>idx;
				idx--;
				cout<<sum(0,0,n-1,idx,idx)<<endl;
			}
		}
	}
}