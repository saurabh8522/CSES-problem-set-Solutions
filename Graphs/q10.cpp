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
ll arr[2505][2505];
struct edge{
	ll a,b,w;
};
vector<edge>graph,graph1;
bool bfs[3001][3001]; 
vector< pair<ll,ll> >grp[2505];
ll dist[2505];
vector<ll>se;
int  main(){
	FastRead;
	ll t=1;
	while(t--){
		graph.clear();
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n+1;i++){
			for(int j=0;j<n+1;j++){
				arr[i][j]=-INF;
				bfs[i][j]=0;
				dist[i]=1e16;
			}
		}
		ll esize1=0;
		map< pair<ll,ll>,bool >mp1;
		for(int i=0;i<m;i++){
			edge e;
			cin>>e.a>>e.b>>e.w;
			e.a--;e.b--;
			graph1.pb(e);
			grp[e.a].pb(mp(e.b,e.w));
		}
		ll esize2=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]!=-INF){
					esize2++;
				}
			}          
		}
		for(int i=0;i<n;i++){
			queue<ll>q;
			q.push(i);
			vector<bool>visited(n,0);
			while(!q.empty()){
				ll node=q.front();
				q.pop();
				if(visited[node]) continue;
				visited[node]=true;
				bfs[i][node]=1;
				for(int i=0;i<grp[node].size();i++){
					if(!visited[grp[node][i].first]){
						q.push(grp[node][i].first);
					}
				}
			}
		}
		vector<ll>s(n,0);
		s[0]=1;
		for(int i=1;i<n-1;i++){
			if(bfs[i][n-1]&&bfs[0][i]){
				s[i]=1;
			}
		}
		s[n-1]=1;
		int c=0,d=0;
		for(int i=0;i<graph1.size();i++){
			edge e= graph1[i];
			if(s[e.a]&&s[e.b]){
				edge e1=e;
				e1.w=(-1)*e.w;
				graph.pb(e1);
			}
		}
		dist[0]=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<graph.size();j++){
				if(dist[graph[j].a]+graph[j].w<dist[graph[j].b]&&dist[graph[j].a]<1e16){
					dist[graph[j].b]=dist[graph[j].a]+graph[j].w;
					//cout<<ed[j].a<<ed[j].b<<ed[j].w<<endl;
				}	
			}
		}
		for(int j=0;j<graph.size();j++){
			if(dist[graph[j].a]+graph[j].w<dist[graph[j].b]&&dist[graph[j].a]<1e16){
				cout<<-1<<endl;
				return 0;
			}
		}
		cout<<(-1)*dist[n-1]<<endl;
	}
}