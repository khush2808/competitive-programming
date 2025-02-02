#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Helper function to multiply two 2x2 matrices modulo MOD
void matrixMultiply(long long a[2][2], long long b[2][2], long long result[2][2]) {
    long long temp[2][2];
    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    temp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    result[0][0] = temp[0][0];
    result[0][1] = temp[0][1];
    result[1][0] = temp[1][0];
    result[1][1] = temp[1][1];
}

// Function to compute matrix exponentiation: M^n
void matrixPower(long long M[2][2], long long n, long long result[2][2]) {
    // Initialize result as the identity matrix
    result[0][0] = result[1][1] = 1;
    result[0][1] = result[1][0] = 0;

    long long base[2][2] = {{M[0][0], M[0][1]}, {M[1][0], M[1][1]}};

    // Exponentiation by squaring
    while (n > 0) {
        if (n % 2 == 1) {
            matrixMultiply(result, base, result);  // Multiply result by the base matrix
        }
        matrixMultiply(base, base, base);  // Square the base matrix
        n /= 2;
    }
}

// Function to calculate the nth Fibonacci number mod MOD
long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Fibonacci matrix
    long long M[2][2] = {{1, 1}, {1, 0}};
    
    // Result matrix to store M^n
    long long result[2][2];
    
    // Compute M^(n-1)
    matrixPower(M, n-1, result);

    // F(n) is stored in result[0][0]
    return result[0][0];
}

int main() {
    long long n;
    cin >> n;
    
    // Output the nth Fibonacci number modulo 10^9 + 7
    cout << fibonacci(n) << endl;

    return 0;
}
