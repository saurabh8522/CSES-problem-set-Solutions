/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
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
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); } 
ll dp[1000005];
// dp[i]= minimum number of coins to make sum i.
ll find(ll n,vector<ll>&v){
	if(n==0) return dp[0]=0;   // coins required for zero sum is zero.
	ll &ans=dp[n];
	if(ans!=-1) return ans;
	ans=INT_MAX;
	for(int i=0;i<v.size();i++){
		if(v[i]<=n){
			ans=min(ans,1+find(n-v[i],v));      // try for ith coin if its value is less than required sum
		}										// take minimum of trying all the coins one by one.
	}
	return ans;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		minus(dp);
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		find(x,v);
		if(dp[x]==INT_MAX) cout<<-1<<endl;      // if sum is not possible return -1.
		else cout<<dp[x]<<endl;
	}
}