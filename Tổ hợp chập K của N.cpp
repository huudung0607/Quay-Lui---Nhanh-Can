
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
int n, a[5005], k;
void result() {
	for (int i = 1; i <= k; i++) {
		cout << a[i];
	}
	cout << endl;
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
	cin >> n >> k;
	Try(1);
}

