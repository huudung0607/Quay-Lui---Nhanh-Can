
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
char c; int k;
string s;
void Try(int i) {
	for (int j = 'A'; j <= c; j++) {
		s += j;
		if (s.size() == k) {
			cout << s << endl;
		}
		else Try(i + 1);
		s.pop_back();
	}
}
int main()
{
	cin >> c >> k;
	Try(1);
}

