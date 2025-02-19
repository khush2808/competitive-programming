#include <bits/stdc++.h>
using namespace std;
long long M = 998244353;

void solve (){
	int n;
	cin >> n;
	long long s = 0; 
	long long c = 0; 
	long long ans = 0; 
	
	for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x == 1) {
					s = (s + 1) % M;
					c++;
			} else if(x == 2) {
					s = (s * 2) % M;
			} else if(x == 3) {
					ans = (ans + (s - c + M)) % M;
			}
	}
	cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--){
solve();
       
    }
    
    return 0;
}