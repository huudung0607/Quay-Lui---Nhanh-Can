
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
int a[5005];
long long sum = 0;
long long sumtmp = 0;
int ans = 0;
void Try(int i) {
	if (sumtmp == sum / 2) {
		ans = 1;
	}
	for (int j = i; j <= n; j++) {
		sumtmp += a[j];
		Try(j + 1);
		sumtmp -= a[j];
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 == 1) {
		cout << 0;
		return 0;
	}
	else {
		Try(1);
		cout << ans;
	}
}

