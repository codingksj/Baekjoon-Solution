#include <stdio.h>
#include <stdlib.h>

int arr[1000001] = { 0, };

int cmp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}