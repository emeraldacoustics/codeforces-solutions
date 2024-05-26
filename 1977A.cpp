#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int n, m;
		cin >> n >> m;

		cout << (n >= m && (n - m) % 2 == 0 ? "Yes" : "No") << endl;
	}

	return 0;
}
