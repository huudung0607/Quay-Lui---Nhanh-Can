#include <iostream>
#include <string>
using namespace std;

int visited[7][7];
int a[7][7];
int n;
string s = "";
string maxBinary = "";
long long maxValue = -1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

long long binaryToDecimal(string num) {
	long long dec = 0;
	for (char c : num) {
		dec = dec * 2 + (c - '0');
	}
	return dec;
}

void Try(int i, int j) {
	if (i == n && j == n) {
		long long val = binaryToDecimal(s);
		if (val > maxValue) {
			maxValue = val;
			maxBinary = s;
		}
		return;
	}
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni >= 1 && nj >= 1 && ni <= n && nj <= n && visited[ni][nj] == 0) {
			visited[ni][nj] = 1;
			s += to_string(a[ni][nj]);
			Try(ni, nj);
			s.pop_back();
			visited[ni][nj] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	visited[1][1] = 1;
	s += to_string(a[1][1]);
	Try(1, 1);
	cout << maxBinary << endl;
}
