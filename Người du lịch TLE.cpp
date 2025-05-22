// O(N!) 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
int a[100], c[100][100], n;
int res = INT_MAX, d = 0;
int visited[100];
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (visited[j] == 0) {
			a[i] = j;
			visited[j] = 1;
			d += c[a[i - 1]][a[i]];
			if (i == n) {
				res = min(res, d + c[a[n]][a[1]]);
			}
			else Try(i + 1);
			visited[j] = 0;
			d -= c[a[i - 1]][a[i]];
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	a[1] = 1;
	visited[1] = 1;
	Try(2);
	cout << res;
}

