#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXL 200010

char s[MAXL];
int L, answer;
vector<int> suffix, lcp, rev;

struct Compare {
	int t;
	vector<int>& gr;
	Compare(int t_, vector<int>& gr_) :t(t_), gr(gr_) {}
	bool operator() (int x, int y) {
		return gr[x] != gr[y] ? gr[x]<gr[y] : gr[x + t]<gr[y + t];
	}
};

vector<int> Suffix(char* S) {
	int n = L;
	vector<int> ret(n), gr(n + 1), gr2(n);
	for (int i = 0; i<n; i++)ret[i] = i, gr[i] = S[i];
	gr[n] = -1;
	for (int i = 1; i<n; i <<= 1) {
		Compare cmp(i, gr);
		sort(ret.begin(), ret.end(), cmp);
		gr2[ret[0]] = 0;
		for (int j = 1; j<n; j++) {
			if (cmp(ret[j - 1], ret[j]))
				gr2[ret[j]] = gr2[ret[j - 1]] + 1;
			else gr2[ret[j]] = gr2[ret[j - 1]];
		}
		for (int j = 0; j<n; j++)gr[j] = gr2[j];
	}
	return ret;
}

void get_lcp() {
	for (int i = 0; i < L; i++)
		rev[suffix[i]] = i;

	int len = 0;
	for (int i = 0; i < L; i++) {
		int k = rev[i];
		if (k) {
			int j = suffix[k - 1];
			while (s[j + len] == s[i + len])
				len++;
			lcp[k] = len;
			if (len)
				len--;
		}
	}
	sort(lcp.begin(), lcp.end());
	answer = lcp[L - 1];
}

int main() {
	scanf("%d %s", &L, s);
	suffix.resize(L + 1);
	lcp.resize(L);
	rev.resize(L);

	suffix = Suffix(s);
	get_lcp();
	printf("%d\n", answer);
	return 0;
}