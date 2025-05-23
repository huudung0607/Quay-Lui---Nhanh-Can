
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
long long a[5005], res = 1e9;
long long sum = 0;
long long used[5005];
long long cnt = 0;
void Try(int i) {
	if (sum > k || cnt >= res) {
		return;
	}
	if (sum == k) {
		res = min(res, cnt);
		return;
	}
	for (int j = i; j <= n; j++) {
		if (used[j] == 0) {
			sum += a[j];
			used[j] = 1;
			cnt++;
			Try(j + 1);
			sum -= a[j];
			used[j] = 0;
			cnt--;
		}
		
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1,greater<long long>());
	Try(1);
	if (res == 1e9 || res == 0) cout << -1;
	else cout << res;
}

