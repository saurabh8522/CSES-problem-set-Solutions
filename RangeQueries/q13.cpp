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
typedef  int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
vector< vector<ll> >base_seg(1005,vector<ll>(4020,0));
vector< vector<ll> >final_seg(3015,vector<ll>(3020,0));
vector< vector<int> >mat(1005,vector<int>(1005,0));
ll n,q; 
void final_build(ll nodey,ll ly,ll ry,ll nodex,ll lx,ll rx){
	if(ly==ry){
		if(lx==rx){
			final_seg[nodex][nodey]=mat[lx][ly];
		}
		else{
			final_seg[nodex][nodey]=final_seg[2*nodex+1][nodey]+final_seg[2*nodex+2][nodey];
		}
		return ;
	}
	ll mid=(ly+ry)>>1;
	final_build(2*nodey+1,ly,mid,nodex,lx,rx);
	final_build(2*nodey+2,mid+1,ry,nodex,lx,rx);
	final_seg[nodex][nodey]=final_seg[nodex][2*nodey+1]+final_seg[nodex][2*nodey+2];
	return;
}
void base_build(ll nodex,ll lx,ll rx){
	if(lx!=rx){
		ll mid=(lx+rx)>>1;
		base_build(2*nodex+1,lx,mid);
		base_build(2*nodex+2,mid+1,rx);
	}
	final_build(0,0,n-1,nodex,lx,rx);
}
void final_update(ll nodey,ll ly,ll ry,ll nodex,ll lx,ll rx,ll ql,ll qr,ll val){
	if(ly==ry){
		if(lx==rx){
			final_seg[nodex][nodey]=val;
		}
		else{
			final_seg[nodex][nodey]=final_seg[2*nodex+1][nodey]+final_seg[2*nodex+2][nodey];
		}
		return;
	}
	ll mid=(ly+ry)>>1;
	if(qr>=ly&&qr<=mid){
		final_update(2*nodey+1,ly,mid,nodex,lx,rx,ql,qr,val);
	}
	else{
		final_update(2*nodey+2,mid+1,ry,nodex,lx,rx,ql,qr,val);
	}
	final_seg[nodex][nodey]=final_seg[nodex][2*nodey+1]+final_seg[nodex][2*nodey+2];
}
void update(ll nodex,ll lx,ll rx,ll ql,ll qr,ll val){
	if(lx!=rx){
		ll mid=(lx+rx)>>1;
		if(ql>=lx&&ql<=mid){
			update(2*nodex+1,lx,mid,ql,qr,val);
		}
		else{
			update(2*nodex+2,mid+1,rx,ql,qr,val);
		}
	}
	final_update(0,0,n-1,nodex,lx,rx,ql,qr,val);
}
ll final_sum(ll node,ll l,ll r,ll ql,ll qr,ll pos){
	if(r<ql||l>qr) return 0;
	if(l>=ql&&r<=qr){
		return final_seg[pos][node];
	}
	ll mid=(l+r)>>1;
	return final_sum(2*node+1,l,mid,ql,qr,pos)+final_sum(2*node+2,mid+1,r,ql,qr,pos);
}
ll sum(ll node,ll l,ll r,ll x1,ll y1,ll x2,ll y2){
	if(x2<l||x1>r) return 0;
	if(l>=x1&&r<=x2){
		return  final_sum(0,0,n-1,y1,y2,node);
	}
	ll mid=(l+r)>>1;
	return sum(2*node+1,l,mid,x1,y1,x2,y2)+sum(2*node+2,mid+1,r,x1,y1,x2,y2);
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		// ll n,q;
		cin>>n>>q;
		char c;
		// mat.resize(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>c;
				if(c=='*'){
					mat[i][j]=1;
				}
			}
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout<<mat[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// base_seg.resize(n,vector<ll>(3*n,0));
		// final_seg.resize(3*n,vector<ll>(3*n,0));
		// for(int i=0;i<n;i++){
			base_build(0,0,n-1);
		// }
		// final_build(0,0,n-1);
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<2*n-1;j++){
		// 		cout<<base_seg[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"printing final tree==>"<<endl;
		// for(int i=0;i<2*n-1;i++){
		// 	for(int j=0;j<2*n-1;j++){
		// 		cout<<final_seg[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int i=0;i<q;i++){
			int type;
			cin>>type;
			if(type==1){
				ll l,r;
				cin>>l>>r;
				l--;r--;
				update(0,0,n-1,l,r,1-mat[l][r]);
		// 		cout<<"printing final tree after update==>"<<endl;
		// for(int i=0;i<2*n-1;i++){
		// 	for(int j=0;j<2*n-1;j++){
		// 		cout<<final_seg[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
				mat[l][r]=1-mat[l][r];
			}
			else{
				ll l1,r1,l2,r2;
				cin>>l1>>r1>>l2>>r2;
				l1--;r1--;l2--;r2--;
				cout<<sum(0,0,n-1,l1,r1,l2,r2)<<endl;
			}
		}
	}
}