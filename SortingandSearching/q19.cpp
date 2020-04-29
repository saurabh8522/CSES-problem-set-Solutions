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
		ll n;
		cin>>n;
		stack<ll>s;
		vector<ll>v(n);
		int a;
		cin>>v[0];
		s.push(0);
		cout<<0<<" ";
		
		for(int i=1;i<n;i++){
			int a;
			cin>>v[i];
		}
		for(int i=1;i<n;i++){
			// cout<<"i="<<i<<" printi"<<endl;
			while(!s.empty()&&v[s.top()]>=v[i]){
				// cout<<s.top()<<" "<<v[s.top()]<<endl;
				s.pop();
				// cout<<"after="<<s.top()<<endl;
			}
			// cout<<i<<" "<<s.top()<<endl;
			if(s.empty()){
				cout<<0<<" ";
			}
			else{
				cout<<s.top()+1<<" ";
			}
			s.push(i);
		}
		cout<<endl;
	}
}