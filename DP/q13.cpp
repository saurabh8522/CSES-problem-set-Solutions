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
ll dp[501][62626];
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
ll modInverse(ll b, ll m) 
{ 
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 

    return (x%m + m) % m; 
} 
ll modDivide(ll a, ll b) 
{ 
    a = a % MOD; 
    ll inv = modInverse(b, MOD); 
    return (inv * a) % MOD; 
}
ll find(ll pos,ll sum,ll n){
	// cout<<pos<<" "<<sum<<endl;
	if(pos==n+1){
		if(sum==0) return 1;
		return 0;
	}
	ll &ans=dp[pos][sum];
	if(ans!=-1) return ans;
	ans=0;
	if(sum>=pos){
		ans=(find(pos+1,sum-pos,n)+find(pos+1,sum,n))%MOD;
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
		for(int i=0;i<501;i++){
			for(int j=0;j<=62626;j++){
				dp[i][j]=-1;
			}
		}
		ll sum=(n*(n+1))/2;
		if(sum&1){
			cout<<0<<endl;
			return 0;
		}
		sum/=2;
		// cout<<sum<<endl;
		find(1,sum,n);
		// cout<<dp[1][sum]<<endl;
		cout<<modDivide(dp[1][sum],2)<<endl;
	}
}