
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
int a[55][55];
int b[55];
int cot[55], xuoi[55], nguoc[55];
long long sum = 0;
long long maxval = -1;
void Try(int i) {
	for (int j = 1; j <= 8; j++) {
		if (cot[j] == 0 && xuoi[i - j + 8] == 0 && nguoc[i + j - 1] == 0) {
			sum += a[i][j];
			cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 1;
			if (i == 8) {
				maxval = max(maxval, sum);
			}
			else Try(i + 1);
			cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 0;
			sum -= a[i][j];
		}
	}
}
int main()
{
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> a[i][j];
		}
	}
	Try(1);
	cout << maxval;
}

