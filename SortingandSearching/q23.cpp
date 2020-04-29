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
		ll n,k;
		cin>>n>>k;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		ll l=0,r=LLONG_MAX;
		ll ans=-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll ck=0,sum=0;
			bool flag=true;
			for(int i=0;i<n;i++){
				if(v[i]>mid){
					flag=false;
					break;
				}
				if(sum+v[i]>mid){
					ck++;
					sum=v[i];
				}
				else{
					sum+=v[i];
				}
			}
			ck++;
			if(ck>k){
				flag=false;
			}
			if(!flag){
				l=mid+1;
			}
			else{
				ans=mid;
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
}