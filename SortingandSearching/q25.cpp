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
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		indexed_set s;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<k;i++){
			s.insert(v[i]);
		}
		ll prev_med=*s.find_by_order((k-1)/2);
		ll cost=0;
		for(int i=0;i<k;i++){
			cost+=abs(v[i]-prev_med);
		}
		cout<<cost<<" ";
		for(int i=k;i<n;i++){
			s.insert(v[i]);
			s.erase(s.find_by_order(s.order_of_key(v[i-k])));
			ll m=*s.find_by_order((k-1)/2);
			// cout<<i<<" "<<m<<" "<<prev_med<<endl;
			cost+=abs(m-v[i])-abs(prev_med-v[i-k]);
			if(k%2==0) cost-=(m-prev_med);
			prev_med=m;
			cout<<cost<<" ";
		}
		cout<<endl;
	}
}