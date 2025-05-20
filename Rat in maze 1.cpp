
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
int n, a[5005][5005];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
void Try(int i, int j) {
	if (i == n && j == n) {
		cout << s << endl;
	}
	for (int k = 0; k < 2; k++) {
		int i1 = i + dx[k], j1 = j + dy[k];
		if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && a[i1][j1] == 1) {
			if (k == 0) {
				s += "D";
			}
			else s += "R";
			Try(i1, j1);
			s.pop_back();
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
	Try(1, 1);
}

