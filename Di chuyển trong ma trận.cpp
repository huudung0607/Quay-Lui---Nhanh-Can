
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
int n, m, a[55][55];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int cnt = 0;
void Try(int i, int j) {
	int tmp = a[i][j];
	if (i == n && j == m) {
		cnt++;
	}
	for (int k = 0; k < 2; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m) {
			Try(i1, j1);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	Try(1, 1);
	cout << cnt;
}

