#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> res;
vector<int> path;       
int sum = 0;

void Try() {
    if (sum == n) {
        res.push_back(path);
        return;
    }
    if (sum > n) return;
    for (int j = 1; j <= n; j++) {
        path.push_back(j);
        sum += j;
        Try();
        sum -= j;
        path.pop_back();
    }
}

int main() {
    cin >> n;
    Try();
    sort(res.begin(), res.end());
    for (auto x : res) {
        for (int i = 0; i < (int)x.size(); i++) {
            cout << x[i];
            if (i != (int)x.size() - 1) cout << " + ";
        }
        cout << endl;
    }
}
