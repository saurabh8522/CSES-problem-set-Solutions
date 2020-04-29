/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   it.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
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
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> //indexed_set;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b,ll m) {ll res=1;a%=m;for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); } 
vector<ll>grp[200005];
ll DP[20][200005];
ll tin[200005],tout[200005];
ll lvl[200005];
ll timer=0;
void dfs(ll node,ll parent,ll step){
	DP[0][node]=parent;
	tin[node]=++timer;
	lvl[node]=step;
	for(int i=0;i<grp[node].size();i++){
		if(grp[node][i]!=parent){
			dfs(grp[node][i],node,step+1);
		}
	}
	tout[node]=++timer;
}
bool is_ancestor(ll u,ll v){
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
ll lca(ll u,ll v){
	if(is_ancestor(u,v)) return u;
	if(is_ancestor(v,u)) return v;
	for(int i=19;i>=0;i--){
		if(!is_ancestor(DP[i][u],v)){
			u=DP[i][u];
		}
	}
	return DP[0][u];
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		for(int i=0;i<n-1;i++){
			ll u,v;
			cin>>u>>v;
			grp[u-1].pb(v-1);
			grp[v-1].pb(u-1);
		}
		dfs(0,0,1);
		for(int i=1;i<20;i++){
			for(int j=0;j<n;j++){
				DP[i][j]=DP[i-1][DP[i-1][j]];
			}
		}
		for(int i=0;i<q;i++){
			ll u,v;
			cin>>u>>v;
			u--,v--;
			ll l=lca(u,v);
			// cout<<"lca="<<l<<endl;
			ll l1=lvl[u]-lvl[l],r1=lvl[v]-lvl[l];
			cout<<l1+r1<<endl;
		}
	}
}