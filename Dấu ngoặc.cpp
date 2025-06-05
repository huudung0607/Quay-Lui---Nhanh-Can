
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
string t = "()[]{}";
void Try(string s, stack<char>st) {
	if (s.size() == n) {
		if (st.empty()) {
			cout << s << " ";
		}
		return;
	}
	for (auto c : t) {
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
			Try(s + c, st);
			st.pop();
		}
		else if (c == ')') {
			if (st.size() && st.top() == '(') {
				char x = st.top();
				st.pop();
				Try(s + c, st);
				st.push(x);
			}
		}
		else if (c == ']') {
			if (st.size() && st.top() == '[') {
				char x = st.top();
				st.pop();
				Try(s + c, st);
				st.push(x);
			}
		}
		else if (c == '}') {
			if (st.size() && st.top() == '{') {
				char x = st.top();
				st.pop();
				Try(s + c, st);
				st.push(x);
			}
		}
	}
}
int main()
{
	cin >> n;
	if (n % 2 != 0) {
		cout << "NOT FOUND";
		return 0;
	}
	else {
		stack<char>st;
		Try("", st);
	}
}

