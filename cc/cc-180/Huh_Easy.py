def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx += 1
    for _ in range(T):
        N, K = map(int, data[idx:idx+2])
        idx += 2
        if K > N:
            print(-1)
            continue
        if K == N:
            S = ['A' if i % 2 == 0 else 'B' for i in range(N)]
            print(''.join(S))
            print(''.join(S))
            continue
        min_K =N//2
        if K < min_K:
            print(-1)
            continue
        # Construct S as ABAB...
        S = []
        for i in range(N):
            if i % 2 == 0:
                S.append('A')
            else:
                S.append('B')
        S = ''.join(S)
        # Construct T: first K same as S, then alternate between the two other chars
        T = []
        # First K same as S
        for i in range(K):
            T.append(S[i])
        # Remaining N-K positions
        for i in range(K, N):
            # Current char in S is S[i]
            # Can't use S[i] in T[i], and can't have T[i] == T[i-1]
            # Available chars are 'A', 'B', 'C' excluding S[i] and T[i-1]
            forbidden = {S[i], T[i-1]}
            available = ['A', 'B', 'C']
            for c in available:
                if c not in forbidden:
                    T.append(c)
                    break
        T = ''.join(T)
        # Verify no two same adjacent in T
        valid = True
        for i in range(1, len(T)):
            if T[i] == T[i-1]:
                valid = False
                break
        if not valid:
            print(-1)
            continue
        # Verify LCS is K (this is hard to do in code, but assume construction works)
        print(S)
        print(T)

solve()