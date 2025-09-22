
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
vector<vector<int>> v;
vector<int> tmp;
int sum = 0;
void Try(int i) {
	if (sum > n) return;
	if (sum == n) v.push_back(tmp);
	for (int j = 1; j <= n; j++) {
		sum += j;
		tmp.push_back(j);
		Try(j);
		//backtrack
		sum -= j;
		tmp.pop_back();
	}
}
int main()
{
	cin >> n;
	Try(1);
	cout << v.size() << endl;
	for (auto x : v) {
		for (int i : x) {
			cout << i << " ";
		}
		cout << endl;
	}
}

