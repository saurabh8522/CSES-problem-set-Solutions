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
struct node{
	ll sum,set,inc,flag;
};
vector<node>seg(1000005);
vector<ll>v(500005); 
void build(ll node,ll l,ll r){
	if(l==r){
		seg[node].sum=v[l];
		seg[node].set=seg[node].inc=seg[node].flag=0;
		return;
	}
	ll mid=(l+r)>>1;
	build(2*node+1,l,mid);
	build(2*node+2,mid+1,r);
	seg[node].sum=seg[2*node+1].sum+seg[2*node+2].sum;
	seg[node].set=seg[node].inc=seg[node].flag=0;
	return;
}
void lazy(ll node,ll l,ll r){
	if(seg[node].flag==1){
		seg[node].flag=0;
		if(seg[node].set!=0){
			seg[node].sum=(r-l+1)*seg[node].set;
			if(l!=r){
				seg[2*node+1].set=seg[node].set;seg[2*node+1].flag=1;
				seg[2*node+2].set=seg[node].set;seg[2*node+2].flag=1;
				seg[2*node+1].inc=seg[2*node+2].inc=0;
			}
			seg[node].set=0;
		}
		if(seg[node].inc!=0){
			seg[node].sum+=(r-l+1)*seg[node].inc;
			if(l!=r){
				seg[2*node+1].inc+=seg[node].inc;seg[2*node+1].flag=1;
				seg[2*node+2].inc+=seg[node].inc;seg[2*node+2].flag=1;
			}
			seg[node].inc=0;
		}
	}
	else if(seg[node].flag==2){
		seg[node].flag=0;
		seg[node].inc=0;
		if(seg[node].set!=0){
			seg[node].sum=(r-l+1)*seg[node].set;
			if(l!=r){
				seg[2*node+1].set=seg[node].set;seg[2*node+1].flag=2;
				seg[2*node+2].set=seg[node].set;seg[2*node+2].flag=2;
				seg[2*node+1].inc=seg[2*node+2].inc=0;
			}
			seg[node].set=0;
		}
	}
}
void update(ll node,ll l,ll r,ll ql,ll qr,ll val,ll type){
	lazy(node,l,r);
	if(l>qr||r<ql) return ;
	if(l>=ql&&r<=qr){
		if(type==1){
			seg[node].sum+=(r-l+1)*val;
			if(l!=r){
				seg[2*node+1].inc+=val;seg[2*node+1].flag=1;
				seg[2*node+2].inc+=val;seg[2*node+2].flag=1;
			}
		}
		else{
			seg[node].sum=(r-l+1)*val;
			if(l!=r){
				seg[2*node+1].set=val;seg[2*node+1].flag=2;
				seg[2*node+2].set=val;seg[2*node+2].flag=2;
				seg[2*node+1].inc=0;
				seg[2*node+2].inc=0;
			}
		}
		return;
	}
	ll mid=(l+r)>>1;
	update(2*node+1,l,mid,ql,qr,val,type);
	update(2*node+2,mid+1,r,ql,qr,val,type);
	seg[node].sum=seg[2*node+1].sum+seg[2*node+2].sum;
	return;
}
ll sum(ll node,ll l,ll r,ll ql,ll qr){
	if(r<ql||l>qr) return 0;
	lazy(node,l,r);
	if(l>=ql&&r<=qr) return seg[node].sum;
	ll mid=(l+r)>>1;
	return sum(2*node+1,l,mid,ql,qr)+sum(2*node+2,mid+1,r,ql,qr);
}
void print(){
	for(int i=0;i<15;i++){
		cout<<"{ sum = "<<seg[i].sum<<"{ set = "<<seg[i].set<<"{ inc = "<<seg[i].inc<<"{ flag = "<<seg[i].flag<<endl;
	}
}
int  main(){
	FastRead;
	ll t=1;
	while(t--){
		ll n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		build(0,0,n-1);
		// print();
		for(int i=0;i<q;i++){
			int type;
			cin>>type;
			if(type==1){
				ll a,b,x;
				cin>>a>>b>>x;
				a--;b--;
				update(0,0,n-1,a,b,x,1);
				// print();
			}
			else if(type==2){
				ll a,b,x;
				cin>>a>>b>>x;
				a--;b--;
				update(0,0,n-1,a,b,x,2);
				// print();
			}
			else{
				ll a,b;
				cin>>a>>b;
				a--;b--;
				cout<<sum(0,0,n-1,a,b)<<endl;
				// print();
			}
		}
	}
}