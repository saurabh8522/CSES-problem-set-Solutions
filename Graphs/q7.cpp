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
vector<string>v; 
bool visited[2505][2505];
pair<ll,ll> DP[2505][2505];
bool flag=false;
ll n,m;
bool valid(ll r,ll c,ll dist){
	// cout<<"in valid"<<endl;
	bool v1[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			v1[i][j]=false;
		}
	}
	queue< pair<ll, pair<ll,ll> > >q;
	q.push(mp(r,mp(c,0)));
	v1[r][c]=true;
	while(!q.empty()){
		pair<ll, pair<ll,ll> >p=q.front();
		q.pop();
		int i=p.first,j=p.second.first,k=p.second.second;
		// cout<<i<<" "<<j<<" "<<k<<endl;
		// if(visited[i][j]) continue;
		// visited[i][j]=true;
		if(v[i][j]=='M') return false;
		if(k>=dist) continue;
		if(i>0&&!v1[i-1][j]&&(v[i-1][j]=='.'||v[i-1][j]=='M')){
			v1[i-1][j]=true;
			q.push(mp(i-1,mp(j,k+1)));
		}
		if(j>0&&!v1[i][j-1]&&(v[i][j-1]=='.'||v[i][j-1]=='M')){
			v1[i][j-1]=true;
			q.push(mp(i,mp(j-1,k+1)));
		}
		if(i<n-1&&!v1[i+1][j]&&(v[i+1][j]=='.'||v[i+1][j]=='M')){
			v1[i+1][j]=true;
			q.push(mp(i+1,mp(j,k+1)));
		}
		if(j<m-1&&!v1[i][j+1]&&(v[i][j+1]=='.'||v[i][j+1]=='M')){
			v1[i][j+1]=true;
			q.push(mp(i,mp(j+1,k+1)));
		}
	}
	return true;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		cin>>n>>m;
		v.resize(n);
		int sr=-1,sc=-1;
		for(int i=0;i<n;i++){
			cin>>v[i];
			for(int j=0;j<m;j++){
				if(v[i][j]=='A'){
					sr=i,sc=j;
				}
				visited[i][j]=false;
			}
		}
		queue< pair<ll, pair<ll,ll> > >q;
		q.push(mp(sr,mp(sc,0)));
		visited[sr][sc]=true;
		string ans="";
		while(!q.empty()){
			pair<ll, pair<ll,ll> >p=q.front();
			q.pop();
			int i=p.first,j=p.second.first,k=p.second.second;
			// cout<<i<<" "<<j<<" "<<k<<endl;
			// if(visited[i][j]) continue;
			// visited[i][j]=true;
			if(i==0||j==0||i==n-1||j==m-1){
				// cout<<"reached"<<endl;
				if(valid(i,j,k)){
					// cout<<valid(i,j,k)<<endl;
					ans="";
					flag=true;
					while(i!=sr||j!=sc){
						ll pi=DP[i][j].first,pj=DP[i][j].second;
						if(j<pj){
							ans+="L";
						}
						else if(i<pi){
							ans+="U";
						}
						else if(i>pi){
							ans+="D";
						}
						else{
							ans+="R";
						}
						i=pi,j=pj;
					}
					reverse(all(ans));
					cout<<"YES"<<endl;
					cout<<ans.size()<<endl;
					cout<<ans<<endl;
					break;
				}
			}
			if(i>0&&!visited[i-1][j]&&v[i-1][j]=='.'){
				visited[i-1][j]=true;
				DP[i-1][j]={i,j};
				q.push(mp(i-1,mp(j,k+1)));
			}
			if(j>0&&!visited[i][j-1]&&v[i][j-1]=='.'){
				visited[i][j-1]=true;
				DP[i][j-1]={i,j};
				q.push(mp(i,mp(j-1,k+1)));
			}
			if(i<n-1&&!visited[i+1][j]&&v[i+1][j]=='.'){
				visited[i+1][j]=true;
				DP[i+1][j]={i,j};
				q.push(mp(i+1,mp(j,k+1)));
			}
			if(j<m-1&&!visited[i][j+1]&&v[i][j+1]=='.'){
				visited[i][j+1]=true;
				DP[i][j+1]={i,j};
				q.push(mp(i,mp(j+1,k+1)));
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
		// else{
		// 	cout<<"YES"<<endl<<ans.size()<<endl<<ans<<endl;
		// }
	}
}