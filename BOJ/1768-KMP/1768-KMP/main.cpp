#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getpi(string P) {
	int size = P.length(), i = 1, j = 0;
	vector<int> pi(size);
	pi[0] = 0;
	while (i < size) {
		if (P[i] == P[j]) {
			pi[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = pi[j - 1];
		else {
			pi[i] = 0;
			i++;
		}
	}
	return pi;
}

vector<int> kmp(string T, string P) {
	vector<int> ans;
	vector<int> pi = getpi(P);
	int n = T.length(), m = P.length(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> ans = kmp(T, P);
	printf("%d\n", ans.size());
	for (int i : ans) 
		printf("%d ", i + 1); 
	return 0;
}