
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

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int n, m;
int a[15][15];
bool visited[15][15];
long long d[15][15];
long long ans = LLONG_MAX;
long long cost;
void Try(int i, int j) {
	if (cost >= ans) return;
	if (i == n && j == m) {
		ans = min(ans, cost);
		return;
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]) {
			visited[i1][j1] = 1;
			cost += a[i1][j1];
			Try(i1, j1);
			visited[i1][j1] = 0;
			cost -= a[i1][j1];
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	visited[1][1] = 1;
	cost = a[1][1];
	Try(1, 1);
	cout << ans;
}

