
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
int n, s;
vector<vector<int>> v;
vector<int>tmp;
int sumtmp = 0;
void Try(int i) {
	if (tmp.size() == n) {
		if (sumtmp == s) {
			v.push_back(tmp);
		}
	}
	for (int j = i; j <= 9; j++) {
		sumtmp += j;
		tmp.push_back(j);
		Try(j + 1);
		tmp.pop_back();
		sumtmp -= j;
	}
}
int main()
{
	cin >> s >> n;
	Try(1);
	if (v.size() == 0) {
		cout << "NOT FOUND";
		return 0;
	}
	for (auto x : v) {
		for (int i = 0; i < x.size(); i++) {
			cout << x[i] << " ";
			if (i != x.size() - 1) {
				cout << "+" << " ";
			}
		}
		cout << endl;
	}
}

