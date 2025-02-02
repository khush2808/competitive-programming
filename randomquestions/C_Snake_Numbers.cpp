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
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
void solve(){
ll n,m;
cin>>n>>m;
auto cntf = [&](ll lim,ll size){
	return binpow(lim,size);
};
auto cntsize = [&](int lim,ll size){
	ll ans = 0;
	for(int i = 1;i<lim;i++){
		ans+=cntf(i,size-1);
	}
	return ans;
};
auto f = [&](ll n){
	string s = to_string(n);
	int size = s.size();
	int lim = s[0]-'0';
	ll ans = 1;
	for(int i = 1;i<size;i++){
		int el = s[i]-'0';
		ans+= (el)*cntf(lim,size-i-1);
	}
	ans+=cntsize(lim,size);
	// cout<<cntsize(lim,size)<<' ';
	for(int i = 2;i<size;i++){
		ans+=cntsize(10,i);
		// cout<<cntsize(10,i)<<'\n';
	}

	return ans;

};
cout<<f(m)-f(n-1);

		
}
int main() {
	IOS
	int t;
t=1;	while(t--){
		solve();
	}
}