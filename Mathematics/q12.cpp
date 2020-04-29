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
const ll  MOD=1000000007;
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b,ll m) {ll res=1;a%=m;for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
ll n;
vector< vector<ll> > matpow(vector<vector<ll> >&r1,vector< vector<ll> >&r2,int n){
	vector< vector<ll> >ans(n, vector<ll>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ll res=( r1[i][k]%MOD*r2[k][j]%MOD)%MOD;
				ans[i][j]=(ans[i][j]%MOD+res%MOD)%MOD;
			}
		}
	}
	return ans;
}  
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll m,k;
		cin>>n>>m>>k;
		vector< vector<ll> >arr(n,vector<ll>(n,0));
		vector< vector<ll> >res(n, vector<ll>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				res[i][j]=(i==j);
			}
		}
		for(int i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			arr[u-1][v-1]++;
		}
		while(k){
			if(k&1) res=matpow(res,arr,n);
			arr=matpow(arr,arr,n);
			k/=2;
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cout<<res[0][n-1]%MOD<<endl;
	}
}