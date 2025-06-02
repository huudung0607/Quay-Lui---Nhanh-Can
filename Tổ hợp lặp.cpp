
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
char b[5005];
char tmp[5005];
int index[5005];
void result() {
	for (int i = 1; i <= k; i++) {
		cout << tmp[index[i]];
	}
	cout << endl;
}
void Try(int i) {
	for (int j = index[i - 1]; j < n; j++) {
		index[i] = j;
		if (i == k) {
			result();
		}
		else Try(i + 1);
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		tmp[i] = b[i];
	}
	sort(tmp , tmp + n);
	index[0] = 0;
	Try(1);
}
