#include <bits/stdc++.h>

#define IOS                \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;
void solve()
{
	int x;
	cin >> x;
	if (x % 33 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main()
{
	IOS int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}