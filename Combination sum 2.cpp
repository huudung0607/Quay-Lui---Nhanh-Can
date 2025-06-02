
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
int n, s;
vector<vector<int>> v;
vector<int>tmp;
long long sumtmp = 0;
vector<int> prime;
bool isprime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
void getprime() {
	for (int i = 2; i <= s; i++) {
		if (isprime(i)) {
			prime.push_back(i);
		}
	}
}
void Try(int i) {
	if (tmp.size() > n || sumtmp > s) {
		return;
	}
	if (tmp.size() == n && sumtmp == s) {
		v.push_back(tmp);
	}
	for (int j = i; j < prime.size(); j++) {
		sumtmp += prime[j];
		tmp.push_back(prime[j]);
		Try(j + 1);
		tmp.pop_back();
		sumtmp -= prime[j];
	}
}
int main()
{
	cin >> s >> n;
	getprime();
	Try(0);
	if (v.size() == 0) {
		cout << "NOT FOUND"; return 0;
	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		for (int i = 0; i < x.size(); i++) {
			cout << x[i] << " ";
			if (i != x.size() - 1) {
				cout << "+" << " ";
			}
		}
		cout << endl;
	}
}

