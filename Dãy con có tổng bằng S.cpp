
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
int n, k, a[5005];
vector<int> v;
vector<vector<int>> tmp;
long long sum = 0;
void Try(int i) {
	for (int j = i; j <= n; j++) {
		if (sum + a[j] <= k) {
			v.push_back(a[j]);
			sum += a[j];
			if (sum == k) {
				tmp.push_back(v);
			}
			else Try(j + 1);
			v.pop_back();
			sum -= a[j];
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	Try(1);	
	if (tmp.empty()) {
		cout << -1; return 0;
	}
	else {
		for (auto x : tmp) {
			cout << "[";
			for (int i = 0; i < x.size(); i++) {
				cout << x[i];
				if (i != x.size() - 1) {
					cout << " ";
				}
			}
			cout << "]" << endl;
		}
	}
}

