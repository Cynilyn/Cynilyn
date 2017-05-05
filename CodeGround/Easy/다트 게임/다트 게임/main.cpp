#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC, N;
	int test_case;
	float BULL, x, y, distance, angle;
	pair <float, float> DOUBLE, TRIPLE;
	int boardScore[] = { 6, 13, 4, 18, 1, 20, 5, 12, 9 ,14, 11, 8 ,16, 7, 19, 3, 17, 2, 15 ,10, 6 };

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int score, totalScore = 0;
		scanf("%f", &BULL);
		scanf("%f %f", &TRIPLE.first, &TRIPLE.second);
		scanf("%f %f", &DOUBLE.first, &DOUBLE.second);
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%f %f", &x, &y);
			distance = sqrt(x*x + y*y);

			if (distance < BULL)
				score = 50;
			else if (DOUBLE.second < distance)
				score = 0;
			else {
				angle = atan2f(y, x) * 180 / M_PI;
				if (angle < 0.0f)
					angle += 360;
				score = boardScore[(int)(angle + 9) / 18];

				if (DOUBLE.first < distance && DOUBLE.second > distance)
					score *= 2;
				else if (TRIPLE.first < distance && TRIPLE.second > distance)
					score *= 3;
			}
			totalScore += score;
		}
		printf("Case #%d\n", test_case);
		printf("%d\n", totalScore);
	}

	return 0;
}