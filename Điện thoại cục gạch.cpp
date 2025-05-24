
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
map<char, string> mp = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"}
,{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
string s;
string tmp;
vector<string> v;

void Try(int i) {
	if (i == s.size()) {
		v.push_back(tmp);
		return;
	}
	for (auto x : mp[s[i]]) {
		tmp.push_back(x);
		Try(i + 1);
		tmp.pop_back();
	}
}

int main()
{
    cin >> s;
	sort(s.begin(), s.end());
	Try(0);
	sort(s.begin(), s.end());
	for (auto x : v) {
		cout << x << " ";
	}
}

