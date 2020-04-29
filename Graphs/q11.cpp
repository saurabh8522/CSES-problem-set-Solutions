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
vector<edge>e;
ll n,m;
vector< pair<ll,ll> >grp[200005];
vector<pair<ll,ll> >rgrp[200005];
bool visited[200005];
ll dists[200005];
ll distt[200005];
void dijik(vector< pair<ll,ll> >*grp,ll s,ll *dist){
	dist[s]=0;
	priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > >q;
	q.push({0,s});
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	while(!q.empty()){
		pair<ll,ll> p= q.top();
		q.pop();
		ll node=p.second;
		if(visited[node]) continue;
		visited[node]=true;
		for(ll i=0;i<grp[node].size();i++){
			ll v=grp[node][i].first;
			if(dist[node]+grp[node][i].second<dist[v]){
				dist[v]=dist[node]+grp[node][i].second;
				q.push(mp(dist[grp[node][i].first],grp[node][i].first));
			}
		}
	}
}
int  main(){
	
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		
		// ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			distt[i]=INF;
			dists[i]=INF;
			visited[i]=false;
		}
		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			grp[u].pb({v,w});
			rgrp[v].pb({u,w});
			e.pb({u,v,w});
		}
		dijik(grp,0,dists);
		// cout<<"s dis"<<endl;
		// for(int i=0;i<n;i++){
		// 	cout<<dists[i]<<" ";
		// }
		// cout<<endl;
		dijik(rgrp,n-1,distt);
		// cout<<"t dis"<<endl;
		// for(int i=0;i<n;i++){
		// 	cout<<distt[i]<<" ";
		// }
		// cout<<endl;
		ll ans=LLONG_MAX;
		for(int i=0;i<e.size();i++){
			ans=min(ans,dists[e[i].u]+distt[e[i].v]+e[i].w/2);
		}
		cout<<ans<<endl;
	}	
}