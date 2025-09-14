#include <bits/stdc++.h>
#include <functional>
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
const int mod = 10007;
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

int possible_message_count(const string &s)
{
	int n = (int)s.size();
	long long ans = 1; // accumulate in 64-bit
	for (int i = 0, j = n - 1; i <= j; i++, j--)
	{
		if (i == j)
		{
			if (s[i] == '?')
				ans = (ans * 26) % mod; // middle char can be any
		}
		else
		{
			char a = s[i], b = s[j];
			if (a == '?' && b == '?')
				ans = (ans * 26) % mod; // choose any letter
			else if (a == '?' || b == '?')
			{
				// only one way: mirror the known character
			}
			else if (a != b)
				return 0; // impossible
		}
	}
	return (int)(ans % mod);
}
int main()
{
	// We need 64-bit because sums can reach up to 1e6 * 3e5 ≈ 3e11
	ll val1 = 0, val2 = 0;
	int n, q;
	cin >> n >> q;
	vector<ll> mr(n + 1, 0);
	vector<ll> mc(n + 1, 0);
	for (int i = 0; i < q; i++)
	{
		string s;
		int x;
		ll num;								// x = row/col index, num = water added
		cin >> s >> x >> num; // WaterRow R X  / WaterColumn C X
		if (x < 1 || x > n)
			continue; // ignore invalid index
		if (s == "WaterRow")
			mr[x] += num;
		else
			mc[x] += num;
	}
	for (ll v : mr)
		val1 = max(val1, v);
	for (ll v : mc)
		val2 = max(val2, v);
	cout << (val1 + val2) << '\n';
	return 0;
}
