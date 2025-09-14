#include <bits/stdc++.h>
#include <functional>
#define int ll
#define ll long long
#define pb push_back
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define c1 cout << "-1\n"
#define all(x) x.begin(), x.end()
#define re(x) x.rbegin(), x.rend()
#define F first
#define S second
#define ii pair<ll, ll>
#define vin           \
	int n;              \
	cin >> n;           \
	vector<int> arr(n); \
	for (auto &i : arr) \
		cin >> i;
#define sz(x) (int)(x).size()
#define vi(x) vector<x>
#define IOS                \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e12;
#ifndef ONLINE_JUDGE
#define debugs(x)    \
	cerr << #x << " "; \
	_print(x);         \
	cerr << ' ';
#define debug(x)     \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#define debugs(x)
#endif

void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.first);
	cerr << ",";
	_print(p.second);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{

	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
ll modInverse(ll A, ll M)
{
	ll x, y;
	ll g = gcdExtended(A, M, &x, &y);
	ll res = (x % M + M) % M;
	return res;
}
ll bpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
ll powmod(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int max_power_block(vector<vector<int>> grid)
{
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n, 0));
	vector<int> row = {0, 1, 0, -1, 0};
	function<int(int, int)> dfs = [&](int x, int y)
	{
		vis[x][y] = 1;
		int ans = grid[x][y];
		for (int i = 0; i < 4; i++)
		{
			int nx = x + row[i];
			int ny = y + row[i + 1];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] != 0)
				ans += dfs(nx, ny);
		}
		return ans;
	};
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j] && grid[i][j] != 0)
				ans = max(ans, dfs(i, j));
		}
	}
	return ans;
}

signed main()
{
	vector<vector<int>> grid = {
			{1, 2, 0, 0},
			{0, 3, 0, 4},
			{5, 0, 0, 4},
			{0, 0, 6, 4}};
	cout << max_power_block(grid) << endl;
}
