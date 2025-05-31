#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<int>> arr(m, vector<int>(n));
	vector<vector<int>> ans(m, vector<int>(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<vector<bool>> vis(m, vector<bool>(n, 0));

	vector<int> dir = {0, 1, 0, -1, 0};
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			for (int it = 0; it < m; it++)
			{
				for (int jt = 0; jt < n; jt++)
					vis[it][jt] = 0;
			}
			queue<pair<int, int>> q;
			q.push({i, j});
		int mi = INT_MAX;
		for (int itt = 0; itt < k; itt++)
		{
			int size = q.size();
// cout<<size<<'\n';
			for (int l = 0; l < size; l++)
			{
				auto z = q.front();
				q.pop();
				int x = z.first;
				int y = z.second;
				vis[x][y]=1;
				for (int p = 1; p < 5; p++)
				{
					int nx = x + dir[p - 1];
					int ny = y + dir[p];
											if(nx<0 or nx>=m or ny<0 or ny>=n or vis[nx][ny])continue;

					if(itt==k-1)mi = min(mi, abs(arr[nx][ny] - arr[x][y]));
					q.push({nx,ny});
				}
			}
		}
		ans[i][j] = mi;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}