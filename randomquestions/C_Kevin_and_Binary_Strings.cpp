#include <bits/stdc++.h>
using namespace std;

string computeXor(string &input, int start, int end) {
    string result(input.size(), '$');
    for (int i = 0; i < input.size() - (end - start + 1); i++) {
        result[i] = input[i];
    }
    for (int i = input.size() - 1, j = end; j >= start; j--, i--) {
        result[i] = (input[i] == input[j]) ? '0' : '1';
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        string input;
        cin >> input;
        int firstZeroIndex = 0;
        while (input[firstZeroIndex] == '1') {
            firstZeroIndex++;
        }

        string maxResult = input;
        int n = input.size();
        maxResult[n - 1] = '0';
        int maxStart = 1, maxEnd = 1;
        int segmentSize = max(1, n - firstZeroIndex);

        for (int i = 0; i <= n - segmentSize; i++) {
            string currentXor = computeXor(input, i, i + segmentSize - 1);
            if (maxResult < currentXor) {
                maxStart = i + 1;
                maxEnd = i + segmentSize;
                maxResult = currentXor;
            }
        }

        cout << "1 " << n << " " << maxStart << " " << maxEnd << "\n";
    }
    return 0;
}
