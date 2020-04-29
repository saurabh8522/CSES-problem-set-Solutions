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
ll dp[100005][101];
// dp[i][j]= number of ways to form array from i to n if digit used at i-1 is j.
ll find(ll pos,vector<ll>&v,ll last,ll m){
	if(last>m) return dp[pos][last]=0;   // we can't choose the digit greater than m
	if(pos==v.size()){
		return 1;     // if we reach at the end,return 1,
	}
	ll &ans=dp[pos][last];
	if(ans!=-1) return ans;
	ans=0;
	if(v[pos]!=0){ // if current element is not zero
		if(pos!=0){
			if(abs(v[pos]-last)>1){    // if absolute difference is greater than 1, we can't move forward with this array.
				ans=0;
				return ans;
			}
		}
		ans=find(pos+1,v,v[pos],m)%MOD;    // we can't change it because it is not zero,
	}
	else{
		ll ans1=0;
		if(last!=0){       // Try all the three cases
			ans1=find(pos+1,v,last,m);
		}
		ll ans2=find(pos+1,v,last+1,m);
		ll ans3=0;
		if(last>1){
			ans3=find(pos+1,v,last-1,m);
		}
		ans=(ans1+ans2+ans3)%MOD;   // add all the three cases answer
	}
	return ans;
}
int  main(){
	FastRead;
	ll t=1;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<100005;i++){
			for(int j=0;j<101;j++){
				dp[i][j]=-1;
			}
		}
		if(v[0]!=0){
			cout<<find(0,v,0,m)%MOD<<endl;
		}
		else{
			ll ans=0;
			for(int i=1;i<=m;i++){
				ans+=find(1,v,i,m)%MOD;
				ans%=MOD;
			}
			cout<<ans<<endl;
		}
	}
}