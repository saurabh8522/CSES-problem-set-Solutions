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
vector<ll>v;
vector<ll>sum;
ll n;
void fin(ll pos,ll s){
	if(pos==n){
		sum.pb(s);
		return ;
	}
	fin(pos+1,s+v[pos]);
	fin(pos+1,s);
}
int  main(){
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		
		cin>>n;
		v.resize(n,0);
		ll s=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
			s+=v[i];
		}
		fin(0,0);
		ll mi=LLONG_MAX;
		for(ll i=0;i<sum.size();i++){
			mi=min(mi,abs(s-sum[i]-sum[i]));
		}
		cout<<mi<<endl;
	}
}