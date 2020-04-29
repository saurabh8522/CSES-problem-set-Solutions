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
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		string s;
		cin>>s;
		string s1=s;
		string temp="#";
		for(int i=0;i<s.size();i++){
			temp+=s.substr(i,1)+"#";
		}
		// temp+="$";
		s=temp;
		ll n=s.size();
		ll P[n]={0};
		ll c=0,r=0;
		// cout<<s<<endl;
		for(int i=1;i<n-1;i++){
			ll mirr=c-(i-c);
			if(mirr>0&&mirr<n&&r>i){
				P[i]=min(P[mirr],r-i);
			}
			while((i-1-P[i])>=0&&(i+1+P[i])<n&&s[i-1-P[i]]==s[i+1+P[i]]){
				P[i]++;
			}
			if(i+P[i]>r){
				r=i+P[i];
				c=i;
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<P[i]<<" ";
		// }
		// cout<<endl;
		ll ans=0,center=0;
		for(int i=0;i<n;i++){
			if(P[i]>ans){
				ans=P[i];
				center=i;
			}
		}
		// cout<<"ans="<<ans<<"center="<<center<<endl;
		string res=s1.substr(ceil((center-1-ans)/(float)2),ans);
		cout<<res<<endl;
	}
}