#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long x = 2; x <= 1e6; x++) {
        long long target = x * x * x + n;
        long long y = cbrt(target); 
        
        if (y * y * y == target) {  
            cout <<   y << " " << x;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}