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
const ll INF=1e16;
struct edge{
	ll u,v,w;
};
vector<edge>graph;
ll dist[2505];
vector<ll>p(2505);
int  main(){
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll vt=-1,we=-1;
		for(int i=0;i<m;i++){
			edge e;
			cin>>e.u>>e.v>>e.w;
			e.u--,e.v--;
			if(e.u==e.v&&e.w<0){
				vt=e.u,we=e.w;
			}
			graph.pb(e);
		}
		if(vt!=-1){
			cout<<"YES"<<endl<<vt+1<<" "<<vt+1<<endl;
			return 0;
		}
		for(int i=0;i<n;i++){
			dist[i]=INF;
		}
		dist[0]=0;
		ll x;
		for(int i=0;i<n;i++){
			x=-1;
			for(int j=0;j<graph.size();j++){
				if(dist[graph[j].u]+graph[j].w<dist[graph[j].v]){
					dist[graph[j].v]=dist[graph[j].u]+graph[j].w;
					p[graph[j].v]=graph[j].u;
					x=graph[j].v;
				}
			}
		}
		if(x==-1){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				x=p[x];
			}
			ll o=x;
			vector<ll>ans;
			do{
				ans.pb(x);
				x=p[x];
			}while(x!=o);
			ans.pb(x);
			reverse(all(ans));
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]+1<<" ";
			}
			cout<<endl;
		}
	}
}