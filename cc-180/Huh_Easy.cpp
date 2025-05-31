#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
			
        if (k<(n)/2  ) {
            cout << "-1\n";
            continue;
        }
        
        string s, t;
        
        char A = 'A', B = 'B';
        char C = 'C';
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                s += A;
                t += C;
            } 
						else{ s+=B;
						t+=B;
}
        }
				k-=n/2;
				for(int i =n%2==0?n-2:n-1;i>=0 and k!=0;i-=2,k--){
					t[i]=A;
				}
      
       
        cout << s << "\n" << t << "\n";
    }
    
    return 0;
}