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
ll dp[5001][5001];
string s1,s2;
ll find(ll n,ll m){
	if(n<0){
		if(m<0) return 0;
		else return m+1;
	}
	if(m<0){
		if(n<0) return 0;
		else return n+1;
	}
	ll &ans=dp[n][m];
	if(ans!=-1) return ans;
	if(s1[n]!=s2[m]){
		ans=min(find(n-1,m-1),min(find(n-1,m),find(n,m-1)))+1;
	}
	else{
		ans=find(n-1,m-1);
	}
	return ans;
} 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		// string s1,s2;
		cin>>s1>>s2;
		ll n=s1.size(),m=s2.size();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				dp[i][j]=-1;
			}
		}
		cout<<find(n-1,m-1)<<endl;
	}
}