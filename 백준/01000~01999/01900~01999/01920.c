#include <stdio.h>
#include <stdlib.h>

int An[100001];
int Am[100001];

int cmp(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) {
        return -1;
    }
    else if (num1 == num2) {
        return 0;
    }
    else {
        return 1;
    }
}

int BinarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0; // 탐색 실패
}

int main() {
    int N, M;
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &An[i]);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++) {
        scanf("%d", &Am[i]);
    }

    qsort(An, N, sizeof(int), cmp);

    for (i = 0; i < M; i++) {
        printf("%d\n", BinarySearch(An, N, Am[i]));
    }

    return 0;
}
