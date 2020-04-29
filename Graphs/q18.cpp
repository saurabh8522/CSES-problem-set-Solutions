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
vector< pair<ll,ll> >grp[100005];
const ll INF=1e16;
ll dist[100005];
ll paths[100005];
ll maxn[100005];
ll minn[100005];
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<n;i++){
			dist[i]=INF;
			paths[i]=0;
			maxn[i]=0;
			minn[i]=INF;
		}
		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			grp[u].pb(mp(v,w));
		}
		dist[0]=0;
		paths[0]=1;
		maxn[0]=minn[0]=1;
		priority_queue< pair<ll,ll> , vector< pair<ll,ll> >,greater< pair<ll,ll> > >q;
		q.push({0,0});
		while(!q.empty()){
			pair<ll,ll>p=q.top();
			q.pop();
			ll node=p.second;
			if(dist[node]<p.first) continue;
			// cout<<node<<" "<<p.first<<" "<<paths[node]<<endl;
			for(ll i=0;i<grp[node].size();i++){
				ll v=grp[node][i].first,w=grp[node][i].second;
				if(dist[v]>dist[node]+w){
					dist[v]=dist[node]+w;
					paths[v]=paths[node];
					maxn[v]=maxn[node]+1;
					minn[v]=minn[node]+1;
					q.push({dist[v],v});
				}
				else if(dist[v]==dist[node]+w){
					paths[v]=(paths[v]+paths[node])%MOD;
					maxn[v]=max(maxn[v],maxn[node]+1);
					minn[v]=min(minn[v],minn[node]+1);
				}	
			}
		}
		// cout<<endl;
		// for(int i=0;i<n;i++){
		// 	cout<<i<<" "<<dist[i]<<" "<<paths[i]<<" "<<minn[i]-1<<" "<<maxn[i]-1<<endl;
		// }
		cout<<dist[n-1]<<" "<<paths[n-1]<<" "<<minn[n-1]-1<<" "<<maxn[n-1]-1<<endl;
	}
}