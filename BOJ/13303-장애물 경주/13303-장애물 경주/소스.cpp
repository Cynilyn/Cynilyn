#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define MAX 987654321

struct coordinate {
	int x;
	int yl;
	int yh;
};

bool operator<(coordinate t, coordinate u) {
	return t.x > u.x;
}

int N, start_y, end_x;
map<int, int> cost;
map<int, int>::iterator iter;
priority_queue<coordinate> pq;
coordinate next_coor;

void map_initialize() {
	bool empty = 0;
	while (!empty && !pq.empty()) {
		next_coor = pq.top();
		if (next_coor.yl < start_y && next_coor.yh > start_y) {
			cost[next_coor.yh] = next_coor.yh - start_y;
			cost[next_coor.yl] = start_y - next_coor.yl;
			empty = 1;
		}
		pq.pop();
	}
}

void map_find() {
	while (!pq.empty()) {
		next_coor = pq.top();
		for (iter = cost.lower_bound(next_coor.yl+1); iter != cost.upper_bound(next_coor.yh - 1); ++iter) {
			if (cost[next_coor.yl])
				cost[next_coor.yl] = min(iter->second + (iter->first - next_coor.yl), cost[next_coor.yl]);
			else
				cost[next_coor.yl] = iter->second + (iter->first - next_coor.yl);

			if (cost[next_coor.yh])
				cost[next_coor.yh] = min(iter->second + (next_coor.yh - iter->first), cost[next_coor.yh]);
			else
				cost[next_coor.yh] = iter->second + (next_coor.yh - iter->first);
		}
		cost.erase(cost.lower_bound(next_coor.yl + 1), cost.upper_bound(next_coor.yh - 1));
		pq.pop();
	}
}

void print_answer() {
	int min = MAX, count = 0;
	map<int, int> temp;
	for (iter = cost.begin(); iter != cost.end(); ++iter) {
		if (iter->second < min) {
			min = iter->second;
			temp.clear();
			temp[iter->first] = iter->second;
			count = 1;
		}
			
		else if (iter->second == min) {
			temp[iter->first] = iter->second;
			count++;
		}
	}
	
	if (min != MAX) {
		printf("%d\n%d ", min + end_x, count);
		for(iter = temp.begin(); iter != temp.end(); ++iter)
			printf("%d ", iter->first);
	}
	else
		printf("%d\n1 %d", end_x, start_y);
}

int main() {
	scanf("%d %d %d", &N, &start_y, &end_x);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &next_coor.x, &next_coor.yl, &next_coor.yh);
		pq.push(next_coor);
	}

	map_initialize();
	map_find();	
	print_answer();
	return 0;
}