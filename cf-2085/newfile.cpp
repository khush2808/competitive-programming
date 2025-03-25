class Solution
{
public:
	int countWay(vector<int> a, vector<int> b)
	{
		int n = a.size();
		int ans = 0;

		vector<int> op(201);
		vector<int> ways(201);
		for (int i = 0; i < 201; i++)
		{
			int val = i - 100;
			op[i] = abs(a[n - 1] - val);
			ways[i] = 1;
		}
		for (int j = n - 2; j >= 0; j--)
		{
			int minops = INT_MAX;
			for (int val = -100; val <= 100; val++)
			{
				int diff = b[j + 1] - b[j];
				int ops = op[diff + val + 100] + abs(a[j] - val);
				op[val + 100] = ops;
				ways[val + 100] = ways[diff + val + 100];
				if (ops < minops)
				{
					minops = ops;
					ans = ways[val + 100];
				}
				if (ops == minops)
				{
					ans += ways[val + 100];
				}
			}
		}
		return ans;
	}
};