
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
int n, k;
int sum = 0;
vector<vector<int>> v;
vector<int> tmp;
int used[100005];
void Try(int i) {
	if (sum == n) {
		v.push_back(tmp);
		return;
	}
	for (int j = i; j <= n; j++) {
		int p = pow(j, k);
		if (sum + p <= n && used[j] == 0) {
			tmp.push_back(j);
			sum += p;
			used[j] = 1;
			Try(j + 1);
			tmp.pop_back();
			sum -= p;
			used[j] = 0;
		}
		else break;
	}
}
int main()
{
	cin >> n >> k;
	Try(1);
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (auto x : v) {
		sort(x.begin(), x.end());
		for (int i = 0; i < x.size(); i++) {
			cout << x[i] << "^" << k;
			if (i != x.size() - 1) {
				cout << " + ";
			}
		}
		cout << endl;
	}
}

