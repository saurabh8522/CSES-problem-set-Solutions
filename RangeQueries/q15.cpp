/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
vector<ll>v(200005); 
vector<ll>seg(1000005);
vector< pair<ll,ll> >lazy(1000005);
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node]=v[l];
		lazy[node]={0,0};
		return;
	}
	ll mid=(l+r)>>1;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	seg[node]=seg[2*node+1]+seg[2*node+2];
	lazy[node]={0,0};
}
ll sum(ll node,ll l,ll r,ll ql,ll qr){
	if(l>qr||r<ql) return 0;
	if(lazy[node].first!=0){
		ll a=lazy[node].first,d=lazy[node].second;
		ll sum=((r-l+1)*(2*a+(r-l)*d))/2;
		seg[node]+=sum;
		ll mid=(l+r)>>1;
		if(l!=r){
			lazy[2*node+1].first+=a;lazy[2*node+1].second+=d;
			lazy[2*node+2].first+=a+(mid-l+1)*d;lazy[2*node+2].second+=d;
		}
		lazy[node]={0,0};
	}
	if(l>=ql&&r<=qr) return seg[node];
	ll mid=(l+r)>>1;
	return sum(2*node+1,l,mid,ql,qr)+sum(2*node+2,mid+1,r,ql,qr);
}
void update(ll node,ll l,ll r,ll ql,ll qr,ll val){
	// cout<<node<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<val<<endl;
	if(lazy[node].first!=0){
		// cout<<lazy[node].first<<" lazty node enyered"<<endl;
		ll a=lazy[node].first,d=lazy[node].second;
		ll sum=((r-l+1)*(2*a+(r-l)*d))/2;
		seg[node]+=sum;
		ll mid=(l+r)>>1;
		if(l!=r){
			lazy[2*node+1].first+=a;lazy[2*node+1].second+=d;
			lazy[2*node+2].first+=a+(mid-l+1)*d;lazy[2*node+2].second+=d;
		}
		lazy[node]={0,0};
	}
	if(l>qr||r<ql) return ;
	if(l>=ql&&r<=qr){
		// cout<<"overlap entered"<<endl;
		ll sum=((r-l+1)*(2*val+(r-l)))/2;
		seg[node]+=sum;
		// cout<<seg[node]<<" "<<sum<<endl;
		ll mid=(l+r)>>1;
		if(l!=r){
			lazy[2*node+1].first+=val;lazy[2*node+1].second+=1;
			lazy[2*node+2].first+=val+(mid-l+1);lazy[2*node+2].second+=1;
		}
		return ;
	}
	ll mid=(l+r)>>1;
	if(mid<max(ql,l)){
		update(2*node+1,l,mid,ql,qr,val);
		update(2*node+2,mid+1,r,ql,qr,val);
	}
	else{
		update(2*node+1,l,mid,ql,qr,val);
		update(2*node+2,mid+1,r,ql,qr,val+(mid-max(ql,l)+1));
	}
	seg[node]=seg[2*node+1]+seg[2*node+2];
	return ;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,0,n-1);
		// for(int i=0;i<10;i++){
		// 	cout<<seg[i]<<" ";
		// }
		// cout<<endl;
		for(int i=0;i<q;i++){
			ll type,a,b;
			cin>>type>>a>>b;
			a--;b--;
			if(type==1){
				update(0,0,n-1,a,b,1);
			}
			else{
				cout<<sum(0,0,n-1,a,b)<<endl;
			}
		}
	}
}