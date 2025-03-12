#include <iostream>
using namespace std;
#define ll long long 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll m = n / 2;
		ll res = 0;
		for (ll a = 0; a < m+1; a++)
		{
			res += a * (n - a) + 1;
		}
		cout << res << "\n";
	}
	return 0;
}