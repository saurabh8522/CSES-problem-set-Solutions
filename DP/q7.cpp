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
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll>a(n),b(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}	
		ll dp[2][x+1];    // DP optimization to save memory
		zero(dp);
		ll c=0;
		// Two Cases:
		// Case 1: Either you purchase this book.dp[i][j]=dp[i-1][j];
		// CAse 2: You purchase this book only if you have sufficient money dp[i][j]=dp[i-1][j-a[i-1]]+b[i-1]
		// Take maximum of both cases
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				if(j>=a[i-1]){
					dp[c][j]=max(dp[1-c][j],dp[1-c][j-a[i-1]]+b[i-1]);   
				}
				else{
					dp[c][j]=dp[1-c][j];
				}
			}
			c=1-c;
		}
		if(n&1) cout<<dp[0][x]<<endl;
		else cout<<dp[1][x]<<endl;
	}
}