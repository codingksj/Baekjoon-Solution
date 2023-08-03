#include<stdio.h>
int main() {
	int N, index, sum, i;
	int arr[1000] = { 0, };
	
	while (1) {
		scanf("%d", &N);
		if(N==-1){
			break;
		}
		//인덱스랑 약수 합 초기화
		index = 0;
		sum = 0;
		//절반보다 큰 약수는 존재하지 않는다!
		for (i = 1; i <= (N/2)+1; i++) {
			if (N % i == 0) {
				arr[index] = i;
				sum += i;
				index++;
			}
		}
		//완전수인 경우 N = arr[0] + arr[1] + ...
		printf("%d", N);
		if (sum == N) {
			printf(" = ");
			for (i = 0; i < index; i++) {
				//마지막 전까지는 "숫자 + "
				if (i < index - 1)
					printf("%d + ", arr[i]);
				//마지막은 "숫자\n"
				else
					printf("%d\n", arr[i]);
			}
		}
		//완전수가 아닌 경우
		else
			printf(" is NOT perfect.\n");
	}
	
	return 0;
}