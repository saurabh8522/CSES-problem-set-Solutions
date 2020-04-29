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
int arr[1001][1001];
void dfs(ll r,ll c,ll n,ll m){
	if(arr[r][c]==0) return;
	arr[r][c]=0;
	if(c>0){
		dfs(r,c-1,n,m);
	}
	if(r>0){
		dfs(r-1,c,n,m);
	}
	if(c<m-1){
		dfs(r,c+1,n,m);
	}
	if(r<n-1){
		dfs(r+1,c,n,m);
	}
	return;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<n ;i++){
			string s;cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='.'){
					arr[i][j]=1;
				}
				else{
					arr[i][j]=0;
				}
			}
		}
		ll count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1){
					count++;
					dfs(i,j,n,m);
				}
			}
		}
		cout<<count<<endl;
	}
}