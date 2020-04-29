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
vector<ll>v,seg;
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node]=1;
	}
	else{
		ll mid=(l+r)>>1;
		build(2*node+1,l,mid);
		build(2*node+2,mid+1,r);
		seg[node]=seg[2*node+1]+seg[2*node+2];
		return ;
	}
}
ll find(ll node,ll l,ll r,ll m){
	if(l==r) return l;
	ll mid=(l+r)>>1;
	if(seg[2*node+1]>=m){
		return find(2*node+1,l,mid,m);
	}
	else{
		return find(2*node+2,mid+1,r,m-seg[2*node+1]);
	}
	return -1;
}
void update(ll node,ll l, ll r,ll index,ll val){
	if(l==r){
		seg[node]=val;
		return ;
	}
	ll mid=(l+r)>>1;
	if(index>=l&&index<=mid){
		update(2*node+1,l,mid,index,val);
	}
	else{
		update(2*node+2,mid+1,r,index,val);
	}
	seg[node]=seg[2*node+1]+seg[2*node+2];
	return ;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		v.resize(n);
		seg.resize(4*n);
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,0,n-1);
		for(int i=0;i<n;i++){
			int m;
			cin>>m;
			// ll idx;
			ll idx=find(0,0,n-1,m);
			cout<<v[idx]<<" ";
			update(0,0,n-1,idx,0);
		}
		cout<<endl;
	}
}