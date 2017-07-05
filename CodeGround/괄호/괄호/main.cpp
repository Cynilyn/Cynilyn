#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int Answer, new_answer, old_answer;

int main(int argc, char** argv)
{
	int T, test_case;
	vector<int> ASCII(128);

	ASCII[40] = 41;
	ASCII[123] = 125;
	ASCII[91] = 93;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		string s;
		stack<int> st;
		Answer = 0;
		old_answer = 0;
		new_answer = 0;
		
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				st.push(s[i]);
			}
			else {
				if (!st.empty() && ASCII[st.top()] == s[i]) {
					new_answer++;
					st.pop();
					if (st.empty())
						old_answer = new_answer;
				}
				else {
					new_answer = old_answer;
					if (new_answer > Answer)
						Answer = new_answer;
					stack<int> empty;
					swap(st, empty);
					new_answer = 0;
				}
			}
		}
		if (!st.empty())
			new_answer = old_answer;
		if (new_answer > Answer) {
			Answer = new_answer;
		}			

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer*2 << endl;
	}
	return 0;
}