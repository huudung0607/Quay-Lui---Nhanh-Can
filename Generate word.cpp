
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
char a[505][505];
int n, m;
string s;
int visited[505][505];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
string tmp = "";
int ans = 0;
void Try(int i,int j) {
	if (tmp == s) {
		ans = 1;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (visited[i1][j1] == 0 && i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m) {
			visited[i1][j1] = 1;
			tmp.push_back(a[i1][j1]);
			Try(i1, j1);
			visited[i1][j1] = 0;
			tmp.pop_back();
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
	cin >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == s[0]) {
				tmp = "";
				tmp.push_back(a[i][j]);
				visited[i][j] = 1;
				Try(i, j);
				visited[i][j] = 0;
			}
		}
	}
	if (ans == 1) cout << "YES";
	else cout << "NO";
}

