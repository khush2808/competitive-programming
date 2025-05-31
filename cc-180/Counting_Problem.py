import sys
MOD = 998244353

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        N, K = map(int, input[ptr:ptr+2])
        ptr +=2
        A = list(map(int, input[ptr:ptr+N]))
        ptr +=N
        
        # Initialize DP tables
        # dp[i][v] represents the number of increasing subsequences ending at position i with value v
        # We'll use a Fenwick tree or prefix sums for efficiency
        max_val = K
        res = 0
        
        # We'll process each element one by one
        # Initialize a DP array that tracks for each value v, the count of sequences ending with v
        dp_prefix = [0]*(max_val +2)
        total = 0
        
        for i in range(N):
            current_val = A[i]
            new_dp_prefix = [0]*(max_val +2)
            if current_val != -1:
                v = current_val
                # The number of sequences ending here with v is 1 (the element itself) plus sum of all sequences ending with u < v
                sum_less = dp_prefix[v-1] if v > 1 else 0
                new_count = (1 + sum_less) % MOD
                # Update new_dp_prefix
                for u in range(v, max_val +1):
                    new_dp_prefix[u] = (dp_prefix[u] + new_count - (dp_prefix[v] - (dp_prefix[v-1] if v >=1 else 0))) % MOD
                # Actually, it's better to compute the delta
                delta = new_count
                # The previous dp_prefix up to v-1 is dp_prefix[v-1], so sum_less is dp_prefix[v-1]
                # The new_dp is adding delta for v
                # So new_dp_prefix is like:
                # for u < v: remains dp_prefix[u]
                # for u >=v: dp_prefix[u] + delta
                # So we can represent new_dp_prefix as follows:
                new_dp_prefix = dp_prefix.copy()
                # Update from v onwards
                for u in range(v, max_val +1):
                    new_dp_prefix[u] = (new_dp_prefix[u] + delta) % MOD
                # Update total sequences
                total = (total + delta) % MOD
                dp_prefix = new_dp_prefix
            else:
                # Need to consider all possible v in 1..K
                # For each v, the delta is (1 + dp_prefix[v-1])
                # The total new sequences is sum over v (1..K) of (1 + dp_prefix[v-1])
                # The new_dp_prefix will be:
                # for each u in 1..max_val, new_dp_prefix[u] = dp_prefix[u] + sum_{v <= u} (1 + dp_prefix[v-1]) when v is chosen
                # But for all possible v, the chosen v affects all u >=v.
                # So the total delta for each v is (1 + dp_prefix[v-1]), and for positions >=v, this delta is added.
                # So the new_dp_prefix can be computed as:
                # new_dp_prefix[u] = dp_prefix[u] + sum_{v <=u} (1 + dp_prefix[v-1]) * 1 (since v is chosen with probability 1 (but wait, no, it's summed over all v possible)
                # Wait, for -1 case, each v in 1..K is possible, and for each, the contribution is (1 + dp_prefix[v-1]) added to all u >=v.
                # So the total delta is for each v, multiplied by 1 (since each v is considered once)
                # So the new_dp_prefix is:
                # new_dp_prefix[u] = dp_prefix[u] + sum_{v=1..u} (1 + dp_prefix[v-1])
                # But since v can be any, the total addition is the sum over v <=u of (1 + dp_prefix[v-1])
                # But during processing, for each v, we add (1 + dp_prefix[v-1]) to all u >=v.
                # So to compute this efficiently, we can proceed as follows:
                # Compute for each v, the term = (1 + dp_prefix[v-1])
                # Then, the delta for u is the sum of all terms for v <=u.
                # So we can compute a prefix sum of these terms.
                terms = [0]*(max_val +2)
                for v in range(1, max_val+1):
                    terms[v] = (1 + (dp_prefix[v-1] if v-1 >=0 else 0)) % MOD
                # Compute prefix sums of terms
                terms_prefix = [0]*(max_val +2)
                for v in range(1, max_val+1):
                    terms_prefix[v] = (terms_prefix[v-1] + terms[v]) % MOD
                # The new_dp_prefix[u] is dp_prefix[u] + terms_prefix[u]
                new_total = 0
                new_dp_prefix = [0]*(max_val +2)
                for u in range(1, max_val+1):
                    new_dp_prefix[u] = (dp_prefix[u] + terms_prefix[u]) % MOD
                    new_total = (new_total + terms[u]) % MOD
                total = (total + new_total) % MOD
                dp_prefix = new_dp_prefix
        res = total % MOD
        print(res)

solve()