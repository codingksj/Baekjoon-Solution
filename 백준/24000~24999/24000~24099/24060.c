#include <stdio.h>

const int MAX = 500000;

int count = 0;
int result;
int N, K;
int A[MAX + 1];
int T[MAX + 1];

void Merge(int start, int mid, int end);
void MergeSort(int start, int end);

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    result = -1;
    MergeSort(0, N - 1);
    printf("%d\n", result);
    return 0;
}

void MergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(start, mid);
        MergeSort(mid + 1, end);
        Merge(start, mid, end);
    }
}

void Merge(int start, int mid, int end) {
    int i, j, t;
    i = start;
    j = mid + 1;
    t = start;
    //비교하면서 정렬
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            T[t++] = A[i++];
        }
        else {
            T[t++] = A[j++];
        }
    }
    //남은 요소 옮기기
    while (i <= mid) {
        T[t++] = A[i++];
    }
    while (j <= end) {
        T[t++] = A[j++];
    }
    //원본으로 복사
    for (i = start; i <= end; i++) {
        A[i] = T[i];
        if (++count == K) {
            result = A[i];
            break;
        }
    }
}