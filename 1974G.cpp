#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int tn = 0; tn < t; tn++)
	{
		int m, x;
		cin >> m >> x;

		vector<int> c(m);
		for (int i = 0; i < m; i++)
			cin >> c[i];
		
		priority_queue<int> que;
		int tot = 0;
		for (int i = 0; i < m; i++)
		{
			if (c[i] <= tot)
			{
				tot -= c[i];
				que.push(c[i]);
			}
			else if (que.size() > 0)
			{
				int t = que.top();
				if (t > c[i])
				{
					que.pop();
					que.push(c[i]);
					tot += t - c[i];
				}
			}
			tot += x;
		}
		cout << que.size() << endl;
	}

	return 0;
}
