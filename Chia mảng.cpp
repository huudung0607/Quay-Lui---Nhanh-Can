
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
vector<int> tmp;
long long sum = 0;
vector<vector<int>> v;
long long sumtmp = 0;
void Try(int i) {	
	for (int i = 0; i < tmp.size(); i++) {
		sumtmp += tmp[i];
	}
	if (sumtmp == sum / k) {
		v.push_back(tmp);
		sumtmp = 0;
	}
	else sumtmp = 0;
	for (int j = i; j <= n; j++) {
		tmp.push_back(a[j]);
		Try(j + 1);
		tmp.pop_back();
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1 ;i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % k != 0) {
		cout << 0;
		return 0;
	}
	else {
		Try(1);
		if (v.size() == k) {
			cout << 1;
			return 0;
		}
		else cout << 0;
	}
}

