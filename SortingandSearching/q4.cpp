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
		ll n,m;
		cin>>n>>m;
		vector<ll>h(n+1),t(m);
		multiset<ll>st;
		for(int i=0;i<n;i++){
			cin>>h[i];
			st.insert(h[i]);
		}
		h[n]=INT_MAX;
		for(int i=0;i<m;i++){
			cin>>t[i];
		}
		int i=0;
		for(i=0;i<m;i++){
			if(st.empty()) break;
			auto it=st.upper_bound(t[i]);
			// if(it!=st.end())
			// cout<<i<<" "<<*it<<endl;
			if(it==st.begin()){
				cout<<-1<<endl;
			}
			else{
				it--;
				cout<<*it<<endl;
				st.erase(it);
			}
		}
		if(i<m){
			for(int j=i;j<m;j++){
				cout<<-1<<endl;
			}
		}
	}
}