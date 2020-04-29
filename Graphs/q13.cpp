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
ll freq[200005]; 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			freq[i]=0;
		}
		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			grp[u].pb({v,w});
		}
		// cout<<"k="<<k<<endl;
		priority_queue< pair<ll,ll> , vector< pair<ll,ll> >, greater< pair<ll,ll> > >q;
		q.push({0,0});
		while(!q.empty()){
			pair<ll,ll>p=q.top();
			q.pop();
			ll node=p.second;
			// cout<<p.first<<" "<<p.second<<" "<<freq[p.second]<<" "<<k<<endl;
			if(freq[p.second]>k) continue;
			if(p.second==n-1){
				// cout<<"enter if"<<endl;
				cout<<p.first<<" ";
				if(freq[n-1]==k-1) break;
			}
			freq[p.second]++;
			for(ll i=0;i<grp[node].size();i++){
				// cout<<"enter for"<<endl;
				ll v=grp[node][i].first,w=grp[node][i].second;
				// cout<<i<<" "<<node<<" "<<v<<" "<<w<<endl;
				if(freq[v]>k) continue;
				q.push({w+p.first,v});
			}
		}
		cout<<endl;
	}	
}