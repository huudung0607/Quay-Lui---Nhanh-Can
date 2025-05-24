
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
int n;
int a[55];
vector<string> v;
vector<int> tmp;
void Try(int i) {
	if (tmp.size() > 1 && is_sorted(tmp.begin(), tmp.end())) {
		string s = "";
		for (auto x : tmp) {
			s += to_string(x) + " ";
		}
		v.push_back(s);
	}
	for (int j = i; j <= n; j++) {
		tmp.push_back(a[j]);
		Try(j + 1);
		tmp.pop_back();
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
	for (auto x : v) {
		cout << x << endl;
	}
}

