#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int w;
	cin >> w;

	cout << (w >= 4 && w % 2 == 0 ? "YES" : "NO") << endl;

	return 0;
}
