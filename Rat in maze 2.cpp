
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
string s = "";
string path = "LRUD";
int n, a[5005][5005];
vector<string> v;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void Try(int i, int j) {
	if (i == n && j == n) {
		v.push_back(s);
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && a[i1][j1] == 1) {
			a[i1][j1] = 0;
			s += path[k];
			Try(i1, j1);
			s.pop_back();
			a[i1][j1] = 1;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (a[1][1] == 1 && a[n][n] == 1) {
		a[1][1] = 0;
		Try(1, 1);
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x << endl;
	}
}

