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
vector< pair<ll,ll> >grp[200005];
priority_queue< pair<ll,ll>,vector< pair<ll,ll> >, greater< pair<ll,ll> > >pq;
ll dist[200005];  
bool visited[200005];
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			visited[i]=false;
			dist[i]=LLONG_MAX;
		}
		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			grp[u-1].pb(mp(v-1,w));
		}
		dist[0]=0;
		pq.push(mp(0,0));
		while(!pq.empty()){
			pair<ll,ll>p=pq.top();
			pq.pop();
			ll node=p.second;
			if(visited[node]) continue;
			visited[node]=true;
			for(int i=0;i<grp[node].size();i++){
				if(dist[grp[node][i].first]>dist[node]+grp[node][i].second){
					dist[grp[node][i].first]=dist[node]+grp[node][i].second;
					pq.push(mp(dist[grp[node][i].first],grp[node][i].first));
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<dist[i]<<" ";
		}	
		cout<<endl;
	}
}