#include<bits/stdc++.h>
#include<functional>
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
#define vin int n;cin>>n;vector<int> arr(n);for(auto&i:arr)cin>>i;
#define sz(x) (int) (x).size()
#define vi(x) vector<x>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9+7;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long  double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

		if (a == 0) {
				*x = 0, *y = 1;
				return b;
		}

		ll x1, y1;
		ll gcd = gcdExtended(b % a, a, &x1, &y1);
		*x = y1 - (b / a) * x1;
		*y = x1;

		return gcd;
}
ll modInverse(ll A, ll M) {
		ll x, y;
		ll g = gcdExtended(A, M, &x, &y);
				ll res = (x % M + M) % M;
			 return res;
		
}
ll bpow(ll a,ll b){
ll ans =1;
while(b){
if(b&1)ans*=a;
a*=a;
b>>=1;
}
return ans;
}
ll powmod(ll a,ll b){
		ll ans =1;
while(b){
if(b&1)ans= (ans*a)%mod;
a=(a*a)%mod;
b>>=1;
}
return ans;
}
vector<int> precomputedPartitions(19, 0);

// Function to precompute partitions for numbers up to 18
void precomputePartitions() {
    int maxN = 18;
    // Create a DP table
    vector<vector<int>> dp(maxN + 1, vector<int>(maxN + 1, 0));

    // Base case: There's one way to partition 0
    for (int i = 0; i <= maxN; ++i) {
        dp[0][i] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= maxN; ++i) {
        for (int j = 1; j <= maxN; ++j) {
            if (i >= j) {
                dp[i][j] = dp[i - j][j] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    for (int i = 0; i <= maxN; ++i) {
        precomputedPartitions[i] = dp[i][i];
    }
}


int partition(int number) {
    if (number < 0 || number >= precomputedPartitions.size()) {
        cerr << "Error: Number out of range (0 to 18)" << endl;
        return -1;
    }
    return precomputedPartitions[number];
}
void solve(){

}
int main() {
IOS
int t;
cin>>t;
while(t--){
solve();
}
}