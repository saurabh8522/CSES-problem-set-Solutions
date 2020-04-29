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
const ll INF=1e16;
struct edge{
	ll u,v,w;
};
vector<edge>e;
vector< pair<ll,ll> >grp[200005];
ll dist[200005];
bool visited[200005];
ll parent[200005];
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			dist[i]=INF;
			visited[i]=false;
			parent[i]=-1;
		}
		for(int i=0;i<m;i++){
			edge ed;
			cin>>ed.u>>ed.v>>ed.w;
			ed.u--,ed.v--;
			e.pb(ed);
			grp[ed.u].pb(mp(ed.v,ed.w));
			grp[ed.v].pb(mp(ed.u,ed.w));
		}
		priority_queue< pair<ll,ll> , vector< pair<ll,ll> >,greater< pair<ll,ll> > >q;
		q.push({0,0});
		dist[0]=0;
		while(!q.empty()){
			pair<ll,ll>p=q.top();
			q.pop();
			if(visited[p.second]) continue;
			visited[p.second]=true;
			ll node=p.second;
			for(int i=0;i<grp[node].size();i++){
				ll v=grp[node][i].first,w=grp[node][i].second;
				if(!visited[v]&&dist[v]>w){
					dist[v]=w;
					parent[v]=node;
					q.push({dist[v],v});
				}
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<i<<" "<<parent[i]<<endl;
		// }
		ll ans=0,c=0;
		for(int i=0;i<m;i++){
			ll u=e[i].u,v=e[i].v;
			if(parent[v]==u||parent[u]==v){
				c++;
				ans+=e[i].w;
			}
		}
		if(c!=n-1){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
}