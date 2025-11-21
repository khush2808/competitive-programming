#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

// We can use a Fenwick (Binary Indexed) Tree or Segment Tree for faster range sums,
// but given the sum of N is up to 5000, an O(N*K) approach with prefix sums can still be feasible.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int N,K;
        cin >> N >> K;
        
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        
        // dp[i][v] = number of strictly increasing subsequences ending exactly at index i, value v
        // We'll also keep prefix[v] = sum of dp for value < v at previous i, to speed up transitions.
        static long long dp[5001][5001];   // dp[i][v]
        static long long prefix[5001];     // prefix[v] = sum of dp[i-1][1..v-1]
        
        // Clear dp
        for(int i=0;i<=N;i++){
            for(int v=0; v<=K; v++){
                dp[i][v] = 0;
            }
        }
        
        // Process the positions in order
        for(int i=0; i<N; i++){
            // Compute prefix sums from dp[i-1] or dp[i-which? Actually from dp[i-1] but let's do per-step
            if(i == 0){
                // No previous row, so prefix sums are 0
                for(int v=1; v<=K; v++){
                    prefix[v] = 0;
                }
            } else {
                // Build prefix from dp[i-1]
                long long runSum = 0;
                for(int v=1; v<=K; v++){
                    runSum = (runSum + dp[i-1][v]) % MOD;
                    prefix[v] = runSum;
                }
            }
            
            if(A[i] == -1){
                // This position can be any value in [1..K]
                for(int v=1; v<=K; v++){
                    // The subsequence of length 1 with this single element
                    long long ways = 1; 
                    // Extend from smaller values at the previous position
                    // = prefix[v-1] if v>1, else 0 if v=1
                    long long ext = (v>1 ? prefix[v-1] : 0);
                    dp[i][v] = (ways + ext) % MOD;
                }
            } else {
                // Fixed value
                for(int v=1; v<=K; v++){
                    dp[i][v] = 0;  // reset
                }
                int x = A[i];
                // The subsequence of length 1
                long long ways = 1;
                // Extend from smaller values
                long long ext = (x>1 ? prefix[x-1] : 0);
                dp[i][x] = (ways + ext) % MOD;
            }
        }
        
        // Sum all dp at the last position i = N-1? Actually we want the sum over all i, all v
        // because any subsequence can end at any i
        long long ans=0;
        for(int i=0; i<N; i++){
            for(int v=1; v<=K; v++){
                ans = (ans + dp[i][v]) % MOD;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}