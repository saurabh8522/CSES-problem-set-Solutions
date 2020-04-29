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
typedef int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
char arr[1001][1001];
int DP[1001][1001]; 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		int sr=0,sc=0,er=0,ec=0;
		for(int i=0;i<n ;i++){
			string s;cin>>s;
			for(int j=0;j<m;j++){
				// if(s[j]=='#'){
				// 	arr[i][j]=0;
				// }
				// else{
				// 	arr[i][j]=1;
				// }
				DP[i][j]=-1;
				arr[i][j]=s[j];
				if(s[j]=='A'){
					sr=i,sc=j;
				}
				if(s[j]=='B'){
					er=i,ec=j;
				}
			}
		}
		// cout<<sr<<" "<<sc<<endl;
		queue< pair<ll, pair< ll,ll > > >q;
		q.push(mp(sr,mp(sc,0)));
		while(!q.empty()){
			pair<ll, pair< ll,ll> > p= q.front();
			int i=p.first,j=p.second.first,k=p.second.second;
			// string str=p.second.second;
			// cout<<i<<" "<<j<<" "<<k<<endl;
			q.pop();
			if(DP[i][j]!=-1)continue;
			DP[i][j]=k;
			if(i==er&&j==ec){
				string ans="";
				cout<<"YES"<<endl;
				while(i!=sr||j!=sc){
					// cout<<i<<" "<<j<<" "<<DP[i][j]<<endl;
					if(i>0&&DP[i-1][j]==k-1){
						ans+="D";
						i--;
					}
					else if(j>0&&DP[i][j-1]==k-1){
						ans+="R";
						j--;
					}
					else if(i<n-1&&DP[i+1][j]==k-1){
						ans+="U";
						i++;
					}
					else{
						ans+="L";
						j++;
					}
					k--;
				}
				// cout<<i<<" "<<j<<" "<<DP[i][j]<<endl;
				reverse(all(ans));
				cout<<ans.size()<<endl;
				cout<<ans<<endl;
				return 0;
			}
			
			if(j>0&&arr[i][j-1]!='#'&&DP[i][j-1]==-1){
				// string temp=p.second.second+"L";
				q.push(mp(i,mp(j-1,k+1)));
			}
			if(i>0&&arr[i-1][j]!='#'&&DP[i-1][j]==-1){
				// string temp=p.second.second+"U";
				q.push(mp(i-1,mp(j,k+1)));
			}
			if(j<m-1&&arr[i][j+1]!='#'&&DP[i][j+1]==-1){
				// string temp=p.second.second+"R";
				q.push(mp(i,mp(j+1,k+1)));
			}
			if(i<n-1&&arr[i+1][j]!='#'&&DP[i+1][j]==-1){
				// string temp=p.second.second+"D";
				q.push(mp(i+1,mp(j,k+1)));
			}
		}
		cout<<"NO"<<endl;
	}
}