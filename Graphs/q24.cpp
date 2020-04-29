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
vector<ll>grp[200005];
vector<ll>rgrp[200005];
stack<ll>s;
bool visited[200005];
vector<ll>ans;
set< pair<ll,ll> >st;
void dfs(ll node){
	if(visited[node]) return;
	visited[node]=true;
	for(int i=0;i<grp[node].size();i++){
		dfs(grp[node][i]);
	}
	s.push(node);
}
void pdfs(ll node){
	if(visited[node]) return;
	visited[node]=true;
	ans.pb(node);
	// cout<<"node="<<node<<endl;
	for(int i=0;i<rgrp[node].size();i++){
		pdfs(rgrp[node][i]);
	}
	return ;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		for(int i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			grp[u-1].pb(v-1);
			rgrp[v-1].pb(u-1);
			st.insert(mp(u-1,v-1));
		}
		dfs(0);
		for(int i=0;i<n;i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		vector< vector<ll> >res;
		while(!s.empty()){
			ll node=s.top();
			s.pop();
			if(visited[node]) continue;
			// visited[node]=true;
			ans.clear();
			pdfs(node);
			// cout<<"node = ="<<node<<" "<<visited[node]<<endl;
			// for(int i=0;i<ans.size();i++){
			// 	cout<<ans[i]<<" ";
			// }
			// cout<<endl;
			res.pb(ans);
		}
		// cout<<res.size()<<endl;
		// for(int i=0;i<res.size();i++){
		// 	for(int j=0;j<res[i].size();j++){
		// 		cout<<res[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		if(res.size()==1) cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
			for(int i=0;i<res[1].size();i++){
				for(int j=0;j<res[0].size();j++){
					if(st.find(mp(res[1][i],res[0][j]))==st.end()){
						cout<<res[1][i]+1<<" "<<res[0][j]+1<<endl;
						break;
					}
				}
			}
		}
	}
}