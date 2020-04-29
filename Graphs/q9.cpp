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
vector< pair<ll,ll> >grp[701];
const ll INF=1e18;
ll dist[701][701];  
bool visited[701];
int  main(){
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m,q;
		cin>>n>>m>>q;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=INF;
			}
			dist[i][i]=0;
		}
		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			u--;v--;
			if(w<dist[u][v]){
				dist[u][v]=dist[v][u]=w;
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
					}
				}
			}
		}
		for(int i=0;i<q;i++){
			ll u,v;
			cin>>u>>v;
			u--;v--;
			if(dist[u][v]==INF){
				cout<<-1<<endl;
			}
			else{
				cout<<dist[u][v]<<endl;
			}
		}
	}
}