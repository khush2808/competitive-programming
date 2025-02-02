#include<bits/stdc++.h>
#define ll long long
#define pb push_back

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
		int size;
	cin >> size;
	vector<int> array(size);
	map<int, int> indexMap;
	for (int i = 0; i < size; i++) {
			cin >> array[i];
			array[i]--;
			indexMap[array[i]] = i;
	}
	int result = 0;
	for (int i = 0; i < size; i++) {
			if (array[i] != i) {
					if (array[array[i]] == i) continue;
					else {
							int index = indexMap[i];
							indexMap[array[index]] = array[i];
							indexMap[array[array[i]]] = index;
							swap(array[array[i]], array[index]);
							result++;
					}
			}
	}
	cout << result << '\n';
	}
}