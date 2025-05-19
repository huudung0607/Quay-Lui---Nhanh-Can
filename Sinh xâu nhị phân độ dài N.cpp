
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
int n, a[5005];
void result() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}
void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			result();
		}
		else Try(i + 1);
	}
}
int main()
{
	cin >> n;
	Try(1);
}

