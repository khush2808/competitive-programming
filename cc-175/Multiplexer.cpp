#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        long long X;
        cin >> N >> X;
        vector<long long> A(N);
        for (int i = 0; i < N; i++){
            cin >> A[i];
        }
        
        // Compute overall frequency
        unordered_map<long long, int> freq;
        for (long long a : A) {
            freq[a]++;
        }
        int answer = 0;
        for (auto &p : freq)
            answer = max(answer, p.second);
        
        // When X == 1, no change happens.
        if(X == 1){
            cout << answer << "\n";
            continue;
        }
        
        // Compute maximum contiguous block length for each value.
        unordered_map<long long, int> maxBlock;
        int i = 0;
        while(i < N) {
            long long cur = A[i];
            int j = i;
            while(j < N && A[j] == cur)
                j++;
            int len = j - i;
            maxBlock[cur] = max(maxBlock[cur], len);
            i = j;
        }
        
        // For each distinct value v (which comes from a potential conversion group),
        // consider converting a contiguous block of v's. They will become b = v * X.
        // Note: if v * X equals v (happens only if X == 1), we already handled that.
        for(auto &p : maxBlock){
            long long v = p.first;
            long long b = v * X;
            int blockLen = p.second;
            int currentB = (freq.count(b) ? freq[b] : 0);
            answer = max(answer, currentB + blockLen);
        }
        
        cout << answer << "\n";
    }
    return 0;
}