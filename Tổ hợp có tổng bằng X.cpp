
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
int n, a[555], k;
long long sumtmp = 0;
vector<int>tmp;
vector<vector<int>> v;
void Try(int i) {
	if (sumtmp == k) {
		v.push_back(tmp);
		return;
	}
	for (int j = i; j <= n; j++) {
		if (sumtmp + a[j] > k) {
			break;
		}	
		sumtmp += a[j];
		tmp.push_back(a[j]);
		Try(j);
		tmp.pop_back();
		sumtmp -= a[j];
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
	if (v.size() == 0) cout << -1;
	else {
		cout << v.size() << endl;
		for (auto x : v) {
			cout << "{";
			for (int i = 0; i < x.size(); i++) {	
				cout << x[i];
				if (i != x.size() - 1) cout << " ";
			}
			cout << "}" << endl;
		}
	}
}

