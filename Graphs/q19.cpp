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
ll DP[33][200005]; 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		vector<ll>v(n);
		for(ll i=0;i<n;i++){
			cin>>v[i];
			DP[0][i]=v[i]-1;
		}
		for(ll i=1;i<=32;i++){
			for(ll j=0;j<n;j++){
				DP[i][j]=DP[i-1][DP[i-1][j]];
			}
		}
		for(ll i=0;i<q;i++){

			ll s,k;
			cin>>s>>k;
			s--;
			ll ans=s;
			// cout<<"ith "<<i<<" query "<<s<<" "<<k<<endl;
			for(ll j=30;j>=0;j--){
				ll b=(1<<j);
				// cout<<k<<" "<<b<<endl;
				if((k&b)>0){
					// cout<<j<<" "<<ans<<endl;
					ans=DP[j][ans];
					// cout<<j<<" "<<ans<<endl;
				}
			}
			cout<<ans+1<<endl;
		}
	}
}