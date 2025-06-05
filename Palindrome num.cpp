
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
string s;
bool check(string t) {
	string tmp = t;
	reverse(tmp.begin(), tmp.end());
	return tmp == t;
}
void Try(vector<string> v, int pos) {
	if (pos == s.size()) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i + pos - 1 <s.size(); i++) {
		string tmp = s.substr(pos, i);
		if (check(tmp)) {
			v.push_back(tmp);
			Try(v, pos + i);
			v.pop_back();
		}
	}
}
int main()
{
	cin >> s;
	vector<string> v;
	Try(v, 0);
}

