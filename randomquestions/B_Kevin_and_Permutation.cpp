#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void solve(){

	int totalNumbers, groupSize;
cin >> totalNumbers >> groupSize;
int currentNumber = totalNumbers;
int startNumber = 1;

while (startNumber <= currentNumber) {
    for (int i = 0; i < groupSize - 1 && startNumber <= currentNumber; i++) {
        cout << currentNumber << ' ';
        currentNumber--;
    }
    if (startNumber > currentNumber) break;
    cout << startNumber << ' ';
    startNumber++;
}

cout << '\n';

}
int main() {
	IOS
	int test;
	cin>>test;
	while(test--){
		solve();
	}
}