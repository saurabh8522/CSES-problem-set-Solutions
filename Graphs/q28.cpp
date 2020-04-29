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
vector<ll>grp[100005];
ll n,m;
bool printcycle(vector<bool>visited,vector<int>path,ll node){
	if(path.size()==n){
		for(int i=0;i<grp[node].size();i++){
			if(grp[node][i]==0){
				for(int j=0;j<path.size();j++){
					cout<<path[j]+1<<" ";
				}
				cout<<1<<endl;
				return true;
			}
		}
		return false;
	}
	for(int i=0;i<grp[node].size();i++){
		ll v=grp[node][i];
		if(!visited[v]){
			visited[v]=true;
			path.pb(v);
			bool ans=printcycle(visited,path,v);
			// if(ans) return true;
			visited[v]=false;
			path.pop_back();
		}
	}
	return false;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			grp[u-1].pb(v-1);
			grp[v-1].pb(u-1);
		}
		vector<int>path;
		path.pb(0);
		vector<bool>visited(n);
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		visited[0]=true;
		if(!printcycle(visited,path,0ll)){
			cout<<"IMPOSSIBLE"<<endl;
		}
	}	
}