#include<stdio.h>
#include<math.h>

int main() {
	int arr[5] = {0,};
	int i, j;
	int key;
	int sum = 0;
	int mid = 0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	//삽입 정렬
	for (i = 1; i < 5; i++) {
		key = arr[i];
		for (j = i - 1; j>=0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	mid = arr[2];
	printf("%d\n", sum/5);
	printf("%d\n", mid);
	return 0;
}

