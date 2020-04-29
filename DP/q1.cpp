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
// dp[i] = number of ways to make sum i using dice outputs 1 to 6.
ll find(ll n){
	if(n==0) return 1;       // there is one way (don't roll the dice) to make sum zero;
	ll &ans=dp[n];
	if(ans!=-1) return ans;       // if answer is already calculated, return it.
	ans=0;
	for(int i=1;i<=6;i++){       // try each outcome for the sum n
		if(n>=i){					// if output is greater than or equal to sum which is left to be made,										// 
			ans+=find(n-i);			// dp[n]=dp[n-1]+dp[n-2]+dp[n-3]+dp[n-4]+dp[n-5]+dp[n-6];
			ans=ans%MOD;
		}
	}
	return ans;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		minus(dp);
		cout<<find(n)<<endl;
	}
}