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
ll sum[200005];
void dfs(ll node,ll p){
	// cout<<node<<" "<<p<<endl;
	if(grp[node].size()==1&&node!=0){
		sum[node]=1;
		return;
	}
	for(int i=0;i<grp[node].size();i++){
		ll v=grp[node][i];
		if(v!=p){
			dfs(v,node);
			// cout<<node<<" "<<v<<" "<<sum[v]<<endl;
			sum[node]+=sum[v];
		}
	}
	sum[node]++;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(int i=0;i<n-1;i++){
			ll v;
			cin>>v;
			grp[i+1].pb(v-1);
			grp[v-1].pb(i+1);
			sum[i]=0;
		}
		sum[n-1]=0;
		dfs(0,-1);
		for(int i=0;i<n;i++){
			cout<<sum[i]-1<<" ";
		}
		cout<<endl;
	}
}