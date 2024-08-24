#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	if (n == 2 && x[0] + 2 <= x[1])
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
		solve();

	return 0;
}
