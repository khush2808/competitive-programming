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

void solve() {
    int length;
    cin >> length;
    string binaryString;
    cin >> binaryString;
    int countOnes = 0;
    int countZeros = 0;
    bool hasConsecutiveOnes = false;

    for(auto character : binaryString) {
        if(character == '0') countZeros++;
        else countOnes++;
    }

    for(int i = 0; i < length - 1; i++) {
        if(binaryString[i] == '1' && binaryString[i + 1] == '1') hasConsecutiveOnes = true;
    }

    if(hasConsecutiveOnes || countOnes >= countZeros || binaryString[0] == '1' || binaryString[length - 1] == '1') {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}