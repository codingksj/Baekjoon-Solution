#include<stdio.h>
int main() {
	int scores[1000] = { 0, };
	int n;
	int sum = 0;
	int max = -1;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &scores[i]);
		if (max < scores[i]) 
			max = scores[i];
		sum += scores[i];
	}

	double new_score = double (sum  * 100) / double (n * max);
	printf("%f", new_score);
	return 0;
}