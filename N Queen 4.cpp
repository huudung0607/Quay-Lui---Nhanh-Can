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
#include <cstring>
using namespace std;
int n, ans = 0;
int a[5005];
int tmp[5005][5005];
int xuoi[5005], nguoc[5005], cot[5005];
vector<vector<int>> v;
vector<int> b;
void in() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == j) b.push_back(j);
		}
	}
}
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0) {
			a[i] = j;
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
			if (i == n) {
				in();
			}
			else Try(i + 1);
			cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;

		}
	}
}
int main()
{
	cin >> n;
	Try(1);
	int cnt = 0;
	for (auto x : b) {
		cout << x << " ";
		cnt++;
		if (cnt == n) {
			cout << endl;
		}
	}
}
