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
const int MOD = 1e9 + 7;

// Helper function to multiply two 2x2 matrices modulo MOD
void matrixMultiply(long long a[2][2], long long b[2][2], long long result[2][2]) {
    long long temp[2][2];
    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    temp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    result[0][0] = temp[0][0];
    result[0][1] = temp[0][1];
    result[1][0] = temp[1][0];
    result[1][1] = temp[1][1];
}

// Function to compute matrix exponentiation: M^n
void matrixPower(long long M[2][2], long long n, long long result[2][2]) {
    // Initialize result as the identity matrix
    result[0][0] = result[1][1] = 1;
    result[0][1] = result[1][0] = 0;

    long long base[2][2] = {{M[0][0], M[0][1]}, {M[1][0], M[1][1]}};

    // Exponentiation by squaring
    while (n > 0) {
        if (n % 2 == 1) {
            matrixMultiply(result, base, result);  // Multiply result by the base matrix
        }
        matrixMultiply(base, base, base);  // Square the base matrix
        n /= 2;
    }
}

// Function to calculate the nth Fibonacci number mod MOD
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Fibonacci matrix
    long long M[2][2] = {{1, 1}, {1, 0}};
    
    // Result matrix to store M^n
    long long result[2][2];
    
    // Compute M^(n-1)
    matrixPower(M, n-1, result);

    // F(n) is stored in result[0][0]
    return result[0][0];
}
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
	ll n,k;
	cin>>n>>k;
	ll c = 1;
	ll a = 0;
	ll b = 1;
	while(true){
		if(b%k==0){
			break;
		}
		int t = b;
		b = b+a;
		 a= t;
		c++;
	}
	cout<<((n%mod)*(c%mod))%mod<<'\n';
		
		
}
int main() {
	IOS
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}