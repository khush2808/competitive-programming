#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> result; // To store all valid expressions
        if (num.empty())
            return result; // Edge case: empty string

        backtrack(result, num, target, "", 0, 0, 0); // Start backtracking
        return result;
    }

    void backtrack(vector<string> &result, string &num, int target, string path, long long index, long long currentValue, long long prevValue)
    {
        // index: current position in num
        // currentValue: value of the expression so far
        // prevValue: value of the last operand (for handling multiplication)

        if (index == num.size())
        {
            if (currentValue == target)
            {
                result.push_back(path); // If the expression equals target, add to result
            }
            return;
        }

        long long operand = 0;  // Build the current operand
        string operandStr = ""; // String representation of the operand for the path

        for (int i = index; i < num.size(); i++)
        {
            if (i > index && num[index] == '0')
                break;                               // Skip leading zeros
            operand = operand * 10 + (num[i] - '0'); // Build the number
            operandStr += num[i];                    // Build the string for the operand

            if (index == 0)
            { // First operand, no operator yet
                backtrack(result, num, target, path + operandStr, operand, operand, operand);
            }
            else
            {
                // Try adding '+'
                backtrack(result, num, target, path + "+" + operandStr, currentValue + operand, currentValue + operand, operand);

                // Try adding '-'
                backtrack(result, num, target, path + "-" + operandStr, currentValue - operand, currentValue - operand, operand * -1); // Note: prevValue for '-' is negative

                // Try adding '*'
                backtrack(result, num, target, path + "*" + operandStr, currentValue - prevValue + (prevValue * operand), currentValue - prevValue + (prevValue * operand), prevValue * operand);
            }
        }
    }
};

// Main function for demonstration
int main()
{
    string num = "123"; // Example input
    int target = 6;     // Example target
    Solution sol;
    vector<string> expressions = sol.addOperators(num, target);

    cout << "Expressions that evaluate to " << target << ":" << endl;
    for (const string &expr : expressions)
    {
        cout << expr << endl;
    }

    return 0;
    // TC: O((4^n)), as in the worst case, we explore all possible ways to insert operators (up to 3 choices per split, plus number building), but with pruning for invalid cases.
    // SC: O(n), for the recursion stack and the path string, where n is the length of num.
}
