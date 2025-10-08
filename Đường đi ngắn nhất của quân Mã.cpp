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

int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int n, s, t, u, v;
int a[505][505];
int cost = 0;
int ans = INT_MAX;
int visited[505][505];
void nhap() {
	cin >> n >> s >> t >> u >> v;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}
void Try(int i, int j) {
	if (cost > ans) return;
	if (i == u && j == v) {
		ans = min(ans, cost);
		return;
	}
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && !visited[i1][j1]) {
			visited[i1][j1] = 1;
			cost += a[i1][j1];
			Try(i1, j1);
			cost -= a[i1][j1];
			visited[i1][j1] = 0;
		}
	}
}
int main()
{
	nhap();
	cost = a[s][t];
	visited[s][t] = 1;
	Try(s, t);
	cout << ans;
}
