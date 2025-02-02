#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define c1 cout<<"-1\n"
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9+7;
void solve(){
int n;
cin>>n;
ll ans = 0;
for(int i = 1;i<=9;i++){
	for(int j=1;j<=9;j++)
	if(i*j==n)continue;
	else ans+=i*j;
}
cout<<ans<<'\n';
		
		
}
int main() {
	IOS
	int t;
t=1;	while(t--){
		solve();
	}
}