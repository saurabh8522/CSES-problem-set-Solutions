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
vector<ll>grp[200005];
bool visited[200005];
ll cycle=-1;
vector<ll>ans;
bool flag=false;
bool dfs(ll node,ll p){
	visited[node]=true;
	for(int i=0;i<grp[node].size();i++){
		ll v=grp[node][i];
		if(!visited[v]){
			bool an=dfs(v,node);
			if(an){
				ans.pb(v);
				if(v==cycle){
					cout<<ans.size()<<endl;
					for(int i=ans.size()-1;i>=0;i--){
						cout<<ans[i]+1<<" ";
					}
					cout<<endl;
					flag=true;
				}
				return true;
			}
		}
		else if(v!=p){
			cycle=v;
			ans.pb(v);
			return true;
		}
	}
	return false;
} 
// bool pdfs(ll node,ll count,ll p){
// 	cout<<node<<" "<<count<<" "<<p<<" "<<visited[node]<<endl;
// 	// if(node==cycle&&count>2&&node!=p&&visited[node]){
// 	// 	ans.pb(node);
// 	// 	return true;
// 	// }
// 	// if(visited[node]) return;
// 	visited[node]=true;
// 	for(int i=0;i<grp[node].size();i++){
// 		ll v= grp[node][i];
// 		if(v==cycle&&count>1){
// 			cout<<"entered if "<<v<<" "<<count<<endl;
// 			ans.pb(v);
// 			return true;
// 		}
// 		bool an=false;
// 		if(!visited[v]){
// 			an=pdfs(v,count+1,node);
// 		}
// 		// pdfs(grp[node][i],count+1,node);
// 		cout<<node<<" "<<count<<" "<<p<<" "<<visited[node]<<" "<<an<<endl;
// 		if(an){
// 			ans.pb(node);
// 		}
// 	}
// 	return false;

// }
int  main(){
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		for(int i=0;i<m;i++){
			int l,r;
			cin>>l>>r;
			grp[l-1].pb(r-1);
			grp[r-1].pb(l-1);
		}
		for(int i=0;i<n;i++){
			if(!visited[i]&&cycle==-1){
				dfs(i,-1);
			}
		}
		// cout<<"cycle="<<cycle<<endl;
		if(cycle==-1){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else if(!flag){
			// for(int i=0;i<n;i++){
			// 	visited[i]=false;
			// }
			// pdfs(cycle,0,-1);
			ans.pb(ans[0]);
			cout<<ans.size()<<endl;
			for(int i=ans.size()-1;i>=0;i--){
				cout<<ans[i]+1<<" ";
			}
			cout<<endl;
		}
	}
}