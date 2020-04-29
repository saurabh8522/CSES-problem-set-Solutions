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
struct node{
	ll a,b,p;
}; 
bool mycomp(const node &a1,const node &a2){
	if(a1.b==a2.b){
		return a1.a>a2.a;
	}
	return a1.b<a2.b;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector< node >v(n);
		for(int i=0;i<n;i++){
			cin>>v[i].a>>v[i].b>>v[i].p;
		}
		sort(all(v),mycomp);
		map<ll,ll>mp;
		ll dp[n+1];
		zero(dp);
		set<ll>st;
		dp[1]=v[0].p;
		st.insert(v[0].b);
		mp[v[0].b]=1;
		for(int i=1;i<n;i++){
			// cout<<"i============>"<<i+1<<endl;
			auto it = st.lower_bound(v[i].a);
			// cout<<*it<<endl;
			if(it==st.begin()){
				dp[i+1]=max(dp[i],v[i].p);
				mp[v[i].b]=i+1;
				st.insert(v[i].b);
			}
			else{
				it--;
				ll el=*it;
				dp[i+1]=max(dp[i],v[i].p+dp[mp[el]]);
				mp[v[i].b]=i+1;
				st.insert(v[i].b);
			}
			// cout<<dp[i+1]<<endl;
		}
		// cout<<1<<" "<<dp[1]<<endl;
		cout<<dp[n]<<endl;
	}
}