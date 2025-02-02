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

ll int mod=1e9+7;
vector <ll int> seive;
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
			
		a = a * a;
		b >>= 1;
	}
	return res;
}

long long binpowmod(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
			res%=mod;
		a = a * a;
		a%=mod;
		b >>= 1;
	}
	return res;
}


bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if(n%2==0)   return false;
	for (int i = 3; i <= sqrt(n); i+=2)
		if (n % i == 0)
			return false;
 
	return true;
}
void SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
 
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			seive.pb(p);
}
void solve(){

		int n;
		cin>>n;
		if(n&1){
			cout<<"Kosuke\n";
		}
		else cout<<"Sakurako\n";
		
}
int main() {
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}