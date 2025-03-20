import math

def find_valid_pair(n, k):
    for a in range(1, n + 1):
        for b in range(a + k, n + 1):  # Ensure |a - b| >= K
            gcd_ab = math.gcd(a, b)
            lcm_ab = (a * b) // gcd_ab
            if abs(gcd_ab - lcm_ab) >= 2 * k:
                return a, b
    return -1, -1


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a, b = find_valid_pair(n, k)
        print(a, b)


if __name__ == "__main__":
    main()
