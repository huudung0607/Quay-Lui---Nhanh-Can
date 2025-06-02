
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
int n, a[5005];
long long sumtmp = 0;
vector<vector<int>> v;
vector<int> tmp;
void Try(int i) {
	if (sumtmp % 2 == 1) {
		v.push_back(tmp);
	}
	for (int j = i; j <= n; j++) {
		sumtmp += a[j];
		tmp.push_back(a[j]);
		Try(j + 1);
		tmp.pop_back();
		sumtmp -= a[j];
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Try(1);
	sort(v.begin(), v.end());
	if (v.size() == 0) {
		cout << "NOT FOUND";
		return 0;
	}
	for (auto x : v) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
}

