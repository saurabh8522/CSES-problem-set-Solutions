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
ll parent[200005];
ll si[200005]; 
// ll rnk[200005];
ll find(ll a){
	if(a==parent[a]){
		return a;
	}
	return parent[a]=find(parent[a]);
}
void unite(ll a,ll b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(si[a]<si[b]){
			swap(a,b);
		}
		parent[b]=a;
		// if(rnk[a]==rnk[b]){
		// 	rnk[a]++;
		// }
		ll t=si[a];
		si[a]+=si[b];
		si[b]+=t;
	}
	
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			parent[i]=i;
			si[i]=1;
			// rnk[i]=0;
		}
		ll num=n,siz=1;
		for(int i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			u--,v--;
			if(find(u)!=find(v)){
				unite(u,v);
				num--;
				siz=max(siz,max(si[find(u)],si[find(v)]));
			}
			cout<<num<<" "<<siz<<endl;
		}
	}
}