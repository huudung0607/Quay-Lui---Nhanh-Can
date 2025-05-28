
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
int n, a[55];
int used[55];
vector<int> tmp;
vector<vector<int>> v;
bool checkfreq(vector<int> v) {
	map<int, int> mp;
	for (int i = 0; i < v.size(); i++) {
		mp[v[i]]++;
		if (mp[v[i]] > 1) {
			return false;
		}
	}
	return true;
}
bool checkminus(vector<int> v) {
	for (int i = 0; i < v.size() - 1; i++) {
		if (abs(v[i + 1] - v[i]) == 1) {
			return false;
		}
	}
	return true;
}
void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (used[j] == 0) {
			used[j] = 1;
			a[i] = j;
			tmp.push_back(a[i]);
			if (i == n) {
				if (checkminus(tmp)) {
					v.push_back(tmp);
				}
			}
			else Try(i + 1);
			used[j] = 0;
			tmp.pop_back();
		}
	}
}

int main()
{
	cin >> n;
	Try(1);
	for (auto x : v) {
		for (auto y : x) {
			cout << y;
		}
		cout << endl;
	}
}

