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



int main() {
	IOS
	int t;
	cin>>t;
	while(t--){
		int n;
cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];

map<int, int> prefixSumIndexMap;
vector<int> dp(n, 0);
int countSegments = 0;
int lastReachable = -1;
int cumulativeSum = 0;

prefixSumIndexMap[0] = -1;

for (int i = 0; i < n; i++) {
    cumulativeSum += arr[i];
    int previousIndex = -2;
    
    if (prefixSumIndexMap.find(cumulativeSum) != prefixSumIndexMap.end()) {
        previousIndex = prefixSumIndexMap[cumulativeSum];
    }
    
    if (previousIndex >= lastReachable) {
        lastReachable = i;
        countSegments++;
    }
    
    prefixSumIndexMap[cumulativeSum] = i;
}

cout << countSegments << '\n';

	}
}