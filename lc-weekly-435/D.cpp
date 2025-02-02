#include<bits/stdc++.h>
typedef long long ll;
const ll INF = 1e18;

class Solution
{
public:
	int maxDifference(string s, int k)
	{
		int n = s.size();
		int res = -1e9;
		const int INF = 1e9;
		for (char a = '0'; a <= '4'; a++)
		{
			for (char b = '0'; b <= '4'; b++)
			{
				if (a == b)
					continue;
				vector<int> F(n + 1, 0), cntA(n + 1, 0), cntB(n + 1, 0);
				vector<int> pa(n + 1, 0), pb(n + 1, 0);
				for (int i = 0; i < n; i++)
				{
					F[i + 1] = F[i];
					cntA[i + 1] = cntA[i];
					cntB[i + 1] = cntB[i];
					pa[i + 1] = pa[i];
					pb[i + 1] = pb[i];
					if (s[i] == a)
					{
						cntA[i + 1]++;
						F[i + 1]++;
						pa[i + 1] = cntA[i + 1] & 1;
					}
					if (s[i] == b)
					{
						cntB[i + 1]++;
						F[i + 1]--;
						pb[i + 1] = cntB[i + 1] & 1;
					}
				}
				vector<int> posA, posB;
				for (int i = 0; i <= n; i++)
				{
					if (i > 0 && s[i - 1] == a)
						posA.push_back(i);
					if (i > 0 && s[i - 1] == b)
						posB.push_back(i);
				}
				vector<int> nextA(n + 1, INF), nextB(n + 1, INF);
				for (int i = 0; i <= n; i++)
				{
					auto it = upper_bound(posA.begin(), posA.end(), i);
					if (it != posA.end())
						nextA[i] = *it;
					it = upper_bound(posB.begin(), posB.end(), i);
					if (it != posB.end())
						nextB[i] = *it;
				}
				vector<int> elig(n + 1, INF);
				vector<bool> valid(n + 1, false);
				for (int i = 0; i <= n; i++)
				{
					if (nextA[i] == INF || nextB[i] == INF)
						continue;
					elig[i] = max(i + k, max(nextA[i], nextB[i]));
					if (elig[i] <= n)
						valid[i] = true;
				}
				int candMin[2][2];
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						candMin[i][j] = INF;
				vector<pair<int, int>> cand;
				for (int i = 0; i <= n; i++)
				{
					if (valid[i])
						cand.push_back({elig[i], i});
				}
				sort(cand.begin(), cand.end());
				int ptr = 0;
				int best = -1e9;
				for (int j = 0; j <= n; j++)
				{
					while (ptr < cand.size() && cand[ptr].first == j)
					{
						int iIdx = cand[ptr].second;
						int p = pa[iIdx], q = pb[iIdx];
						candMin[p][q] = min(candMin[p][q], F[iIdx]);
						ptr++;
					}
					if (j >= k)
					{
						int needA = 1 - pa[j];
						int needB = pb[j];
						if (candMin[needA][needB] != INF)
						{
							int diff = F[j] - candMin[needA][needB];
							best = max(best, diff);
						}
					}
				}
				res = max(res, best);
			}
		}
		return res;
	}
};