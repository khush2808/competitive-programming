typedef long long ll;
const ll INF = 1e12;
ll gcd(ll a, ll b){ 
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& tgt) {
       

        int n = nums.size();
        int m = tgt.size();
        int full = (1 << m) - 1;
        vector<ll> dp(1 << m, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<ll> newdp = dp;
            for (int s = 1; s < (1 << m); s++) {
                ll curLcm = 1;
                bool valid = true;
                for (int j = 0; j < m; j++) {
                    if (s & (1 << j)) {
                        curLcm = lcm(curLcm, tgt[j]);
                        if (curLcm > 1e12) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) continue;
                ll cur = nums[i];
                ll mult = (cur + curLcm - 1) / curLcm;
                ll cand = mult * curLcm;
                ll cost = cand - cur;
                for (int mask = full; mask >= 0; mask--) {
                    if (dp[mask] == INF) continue;
                    int newMask = mask | s;
                    newdp[newMask] = min(newdp[newMask], dp[mask] + cost);
                }
            }
            dp = newdp;
        }
        return dp[full];
    }
};