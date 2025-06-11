#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int totalBeautySum = 0;

        for (int i = 0; i < n; i++)
        {                                      // Start of each substring
            vector<int> freq(26, 0);           // Frequency array for characters in the substring
            int maxFreq = 0;                   // Max frequency in the current substring
            int minFreqExcludingMax = INT_MAX; // Min frequency excluding the max (for beauty calc)

            for (int j = i; j < n; j++)
            { // End of each substring
                char ch = s[j];
                if (isVowel(ch))
                { // Only track vowels as per the problem
                    freq[ch - 'a']++;
                    maxFreq = max(maxFreq, freq[ch - 'a']);
                }

                // Update minFreqExcludingMax only if there are other characters
                int minNonZeroFreq = INT_MAX;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > 0)
                    {
                        if (freq[k] != maxFreq)
                        {
                            minFreqExcludingMax = min(minFreqExcludingMax, freq[k]);
                        }
                        minNonZeroFreq = min(minNonZeroFreq, freq[k]);
                    }
                }

                // Beauty is maxFreq - min non-zero freq (if substring has >1 unique char)
                if (j >= i)
                { // Ensure substring is valid
                    int uniqueChars = 0;
                    for (int k = 0; k < 26; k++)
                    {
                        if (freq[k] > 0)
                            uniqueChars++;
                    }
                    if (uniqueChars > 1)
                    {
                        totalBeautySum += (maxFreq - minNonZeroFreq);
                    }
                }
            }
        }

        return totalBeautySum;
    }

    bool isVowel(char ch)
    {
        ch = tolower(ch); // Case insensitive
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution sol;
    cout << "Sum of beauty: " << sol.beautySum(s) << endl;
    return 0;
}
