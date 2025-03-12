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
void solve()
{
}
int countEfficientFormations(string s, vector<bool> e, int k)
{
	int n = s.size();
	int ans = 0;
	set<string> st;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		string curr;
		for (int j = i; j < n; j++)
		{
			curr += s[j];
			if (!e[s[j] - 'a'])
				cnt++;
			if (cnt <= k)
				st.insert(curr);
			else
				break;
		}
	}
	return st.size();
}
vector<int> use(1e5 + 1, 0);
vector<int> encryptionValidity(int iCnt, int vp, vector<int> keys)
{
	vector<int> ans;
	fill(use.begin(), use.end(), 0);
	sort(keys.begin(), keys.end());
	int n = keys.size();
	int ma = 0;

	for (int i = 0; i < n; i++)
	{
		int el = keys[i];
		int cnt = 0;
		if (el == 1)
			continue;
		use[el]++;
		for (int j = 2; j * j <= el; j++)
		{
			if (el % j == 0)
				cnt += use[j];
		}
		ma = max(ma, cnt);
	}

	return ans;
}
int f(int icnt, int vp, vector<int> keys)
{
	fill(use.begin(), use.end(), 0);
	sort(keys.begin(), keys.end());
	int n = keys.size();
	int ma = 0;

	for (int i = 0; i < n; i++)
	{
		int el = keys[i];
		int cnt = 0;
		if (el == 1)
			continue;
		use[el]++;
		for (int j = 1; j * j <= el; j++)
		{
			if (el % j == 0)
			{
				if (el / j != j)
				{
					cnt += use[j];
					cnt += use[el / j];
				}
				else
					cnt += use[j];
			}
		}
		ma = max(ma, cnt);
	}

	return ma;
}
signed main()
{

	cout << f(100, 1000, {2});

	return 0;
}