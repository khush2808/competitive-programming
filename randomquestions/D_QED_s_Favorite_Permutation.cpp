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
	
		
}
int main() {
	IOS
	int test;
	cin>>test;
	while(test--){
		int n,q;
	cin>>n>>q;
	vector<pair<int,int>> arr(n);
	vector<int > order(n);
	for(int i = 0;i<n;i++){cin>>arr[i].first;
	arr[i].second = i;
	}
	sort(arr.begin(),arr.end());
	for(int i = 0;i<n;i++){
		order[arr[i].second]=i;
	}
	string s;
	cin>>s;
	vector<int> queries(q);
	vector<int> pref(n,0);
	pref[0]=order[0];
	for(int i = 1;i<n;i++){
		pref[i]=max(pref[i-1],order[i]);
	}
	set<int> st;
	char prev = 'R';
	
	for(int i = 1;i<n;i++){
		char curr = s[i];
		
		if(prev =='L' and curr == 'R'){
			if(pref[i]>=i){st.insert(i);
			// cout<<"here";}
			}
				prev = curr;

		}
		
	
	for(auto &i:queries){
		cin>>i;
		if(s[i-1]=='L'){
			if(s[i]=='R'){
				if(pref[i]>=i){st.erase(i);
				// cout<<"here1"<<st.size();
				}
			}
			if(s[i-2]=='L'){
				if(pref[i-1]>=i-1)st.insert(i);
			}
			s[i-1]='R';
		}
		else if(s[i-1]=='R'){

			if(s[i-2]=='L'){
				if(pref[i-1]>=i-1)st.erase(i-1);
			}
			if(s[i]=='R'){
				if(pref[i]>=i)st.insert(i);
			}
			s[i-1]='L';
		}
		cout<<s<<' ';
		if(st.size())cout<<<<'\n';
		else cout<<"YEs\n";
	
	}
} 
}}