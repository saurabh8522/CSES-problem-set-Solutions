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
void base_build(ll node,ll l,ll r,ll row){
	if(l==r){
		base_seg[row][node]=mat[row][l];
		return ;
	}
	ll mid=(l+r)>>1;
	base_build(2*node+1,l,mid,row);
	base_build(2*node+2,mid+1,r,row);
	base_seg[row][node]=base_seg[row][2*node+1]+base_seg[row][2*node+2];
}
void final_build(ll node,ll l,ll r){
	if(l==r){
		for(int i=0;i<3*n;i++){
			final_seg[node][i]=base_seg[l][i];
		}
		return ;
	}
	ll mid=(l+r)>>1;
	final_build(2*node+1,l,mid);
	final_build(2*node+2,mid+1,r);
	for(int i=0;i<3*n;i++){
		final_seg[node][i]=final_seg[2*node+1][i]+final_seg[2*node+2][i];
	}
	return;
}
void final_update(ll node,ll l,ll r,ll col,ll val,ll pos){
	if(l==r){
		final_seg[pos][node]=val;
		return;
	}
	ll mid=(l+r)>>1;
	if(col>=l&&col<=mid){
		final_update(2*node+1,l,mid,col,val,pos);
	}
	else{
		final_update(2*node+2,mid+1,r,col,val,pos);
	}
	final_seg[pos][node]=final_seg[pos][2*node+1]+final_seg[pos][2*node+2];
}
void update(ll node,ll l,ll r,ll ql,ll qr,ll val){
	if(l==r){
		final_update(0,0,n-1,qr,val,node);
		return ;
	}
	ll mid=(l+r)>>1;
	if(ql>=l&&mid>=ql){
		update(2*node+1,l,mid,ql,qr,val);
	}
	else{
		update(2*node+2,mid+1,r,ql,qr,val);
	}
	for(int i=0;i<3*n;i++){
		final_seg[node][i]=final_seg[2*node+1][i]+final_seg[2*node+2][i];
	}
}
ll final_sum(ll node,ll l,ll r,ll ql,ll qr,ll pos){
	// cout<<"in final sum"<<" "<<ql<<" "<<qr<<" "<<node<<" "<<pos<<endl;
	if(r<ql||l>qr) return 0;
	if(l>=ql&&r<=qr){
		return final_seg[pos][node];
	}
	ll mid=(l+r)>>1;
	return final_sum(2*node+1,l,mid,ql,qr,pos)+final_sum(2*node+2,mid+1,r,ql,qr,pos);
}
ll sum(ll node,ll l,ll r,ll x1,ll y1,ll x2,ll y2){
	// cout<<"in sum"<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<node<<endl;
	if(x2<l||x1>r) return 0;
	if(l>=x1&&r<=x2){
		return  final_sum(0,0,n-1,y1,y2,node);
		// cout<<"final sum="<<s<<endl;
		// return s;
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
		for(int i=0;i<n;i++){
			base_build(0,0,n-1,i);
		}
		final_build(0,0,n-1);
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
			// int type;
			// cin>>type;
			// if(type==1){
				// ll l,r;
				// cin>>l>>r;
				// l--;r--;
				// update(0,0,n-1,l,r,1-mat[l][r]);
				// mat[r][r]=1-mat[r][r];
			// }
			// else{
				ll l1,r1,l2,r2;
				cin>>l1>>r1>>l2>>r2;
				l1--;r1--;l2--;r2--;
				cout<<sum(0,0,n-1,l1,r1,l2,r2)<<endl;
			// }
		}
	}
}