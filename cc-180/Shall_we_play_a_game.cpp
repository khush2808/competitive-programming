#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
 
long long modexp(long long base, long long exp) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long ans;
        if(n % 2 == 1){
            ans = modexp(2, n-1);
        } else {
            ans = (3 * modexp(2, n-2)) % mod;
        }
        cout << ans % mod << "\n";
    }
    return 0;
}