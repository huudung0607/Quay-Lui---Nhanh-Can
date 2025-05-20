
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
int n, k, s, a[500];
int cnt = 0;
int sum = 0;
void result() {
	for (int i = 1; i <= k; i++) {
		sum += a[i];
	}
	if (sum == s) cnt++;
	sum = 0;
}
void Try(int i) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k) {
			result();
		}
		else Try(i + 1);
	}
}
int main()
{
	cin >> n >> k >> s;
	Try(1);
	cout << cnt;
}

