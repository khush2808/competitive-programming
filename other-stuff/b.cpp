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
#define debug(x, y, z, w) debugs(x) debugs(y) debugs(z) debugs(w)
#define debug(x, y, z) debugs(x) debugs(y) debugs(z)
#define debug(x, y) debugs(x) debugs(y)
#define debug(x, y) debugs(x) debugs(y)
#define debug(x)     \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
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
#define ll long long
vector<ll> solve(vector<vector<int>> edges, vector<int> values, vector<vector<int>> queries)
{
	int n = values.size();
	vector<int> adj[n + 1];
	vector<int> lazy(n + 1);
	int add = 0;
	for (auto i : edges)
	{
		int u = i[0]-1;
		int v = i[1]-1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (auto i : queries)
	{
		bool one = i[0] == 1;
		int x = i[1]-1;
		int y = i[2];
		if (one)
		{
			lazy[x]+=y;
		}
		else
		{
			add +=y;
			lazy[x]-=y;
		}
	}
	vector<ll> ans(n,add);
	debug(lazy);
	
	for(int i = 0;i<n;i++){
		ans[i]+=values[i];
	}
	debug(ans);
	queue<int> q;
	q.push(0);
	vector<bool> vis(n,0);
	while(!q.empty()){

		int x = q.front();q.pop();
		vis[x]=1;
		cout<<x<<' ';

		int y = lazy[x];
		ans[x]+=y;
		for(auto i:adj[x]){
			if(!vis[i]){
			lazy[i]+=y;
			q.push(i);}
		}
	}
	debug(add);
	debug(lazy);
	return ans;
}
signed main()
{
	IOS
	vector<ll> x = solve({{1,2},{1,3},{2,4},{3,5}},{1,2,3,4,5},{{1,1,2},{2,2,-2},{1,3,1},{1,4,5},{1,1,-1}});
	debug(x);
}