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
	// FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(n<=3){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		vector< pair<ll, pair<ll,ll> > >sum;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				sum.pb(mp(v[i]+v[j],mp(i,j)));
			}
		}
		sort(all(sum));
		vector<ll>w(sum.size());
		for(int i=0;i<sum.size();i++){
			w[i]=sum[i].first;
		}
		for(int i=0;i<sum.size()-1;i++){
			ll val=sum[i].first;
			// cout<<"i="<<i<<" "<<"val= "<<val<<endl;
			if(2*val>x) break;
			auto it = lower_bound(w.begin()+i+1,w.end(),x-val);
			ll a=sum[i].second.first;
			ll b=sum[i].second.second;
			ll c,d;
			while(*it==x-val){
				ll idx=it-w.begin();
				c=sum[idx].second.first;
				d=sum[idx].second.second;
				if(a==c||a==d||b==c||b==d){
					it++;
					continue;
				}
				cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
				return 0;
			}
		}
		cout<<"IMPOSSIBLE"<<endl;
	}
}