#include <stdio.h> 
#define maxn 1005 
int m, n; 
int px[maxn]; 
int py[maxn]; 
int dist[maxn][maxn]; 
int c[maxn][maxn];
int d[maxn][maxn]; 
int trace[maxn]; 
int abs(int val) { return val > 0 ? val : -val; } 

void select_min(int i) { 
	int k, mini; 
	int minv = 0x7fffffff; 
	if(i == 1) { 
		c[i][i + 1] = 0;
		d[i][i + 1] = 1; 
		return; 
	} 
	for(k=1; k<i; k++) { 
		if(minv > c[k][i] + dist[k][i + 1]) {
			minv = c[k][i] + dist[k][i + 1]; mini = k; 
		} 
	} 
	c[i][i + 1] = minv; 
	d[i][i + 1] = mini; 
} 

void output() {
	int i, j, car; 
	int answer = 0x7fffffff;
	for(i=1; i<n; i++) { 
		if(answer > c[i][n]) {
			car = i; 
			answer = c[i][n]; 
		}	
	}
	i = car; 
	printf("%d\n", answer);
	for(j=n; j>2; --j) {
		trace[j - 1] = i; 
		if(d[i][j]) 
			i = d[i][j];
	} 
	if(trace[j] == 1) 
		car = 2; 
	else car = 1;
	printf("%d\n", car);
	for(++j; j<n; ++j) { 
		if(trace[j] != trace[j - 1]) 
			car = 3 - car; 
		printf("%d\n", car);
	} 
} 

int main() { 
	int i, j, car;
	scanf("%d %d", &m, &n);
	n += 2;
	for (i = 3; i <= n; i++)
		scanf("%d %d", px + i, py + i);
	px[1] = 1; py[1] = 1; px[2] = m; py[2] = m;
	for (i = 1; i<n; ++i) {
		dist[i][i] = 0;
		for (j = i + 1; j <= n; ++j) {
			dist[i][j] = abs(px[i] - px[j]) + abs(py[i] - py[j]);
			dist[j][i] = dist[i][j];
		}
	}
	dist[1][2] = 0;
	dist[2][1] = 0;
	
	
	for (i = 1; i <= n; i++) {
		select_min(i);
		for (j = i + 2; j <= n; j++) {
			d[i][j] = 0;
			c[i][j] = c[i][j - 1] + dist[j - 1][j];
		}
	}

	output(); 
	return 0;
}