#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> A(N);
	int maxA = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		maxA = max(maxA, A[i]);
	}

	// freq[x] = number of Ai equal to x
	vector<long long> freq(maxA + 2, 0);
	for (int x : A)
		freq[x]++;

	vector<int> result;
	long long carry = 0;
	long long active = N;

	// process digit positions
	for (int pos = 0; pos < maxA; pos++)
	{
		long long sum = active + carry;
		result.push_back(sum % 10);
		carry = sum / 10;
		active -= freq[pos + 1]; // those with length == pos+1 stop contributing
	}

	// handle remaining carry
	while (carry > 0)
	{
		result.push_back(carry % 10);
		carry /= 10;
	}

	// remove leading zeros (if any)
	while (result.size() > 1 && result.back() == 0)
		result.pop_back();

	// print reversed (most significant digit first)
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];

	cout << '\n';
	return 0;
}
