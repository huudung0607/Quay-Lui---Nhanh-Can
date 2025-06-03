
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
string s;
int a[5005];
void in() {
	for (int i = 1; i <= k; i++) {
		cout << s[a[i] - 1];
	}
	cout << endl;
}
void Try(int i) {
	for (int j = a[i-1]; j <= n; j++) {
		a[i] = j;
		if (i == k) {
			in();
		}
		else Try(i + 1);
	}
}
int main()
{
	cin >> n >> k >> s;
	a[0] = 1;
	sort(s.begin(), s.end());
	Try(1);
}

