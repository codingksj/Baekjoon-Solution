#include<stdio.h>

#define MAX 100001
int Numbers[MAX];

typedef struct MyStruct1 {
    int asc;
    int des;
}Status;

int main(void) {
    Status max = {1,1};
    Status cur = {1,1};
    int N;
    int ans;
   
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Numbers[i]);
    }
    for (int i = 1; i < N; i++) {
        //오름차순
        if (Numbers[i] >= Numbers[i - 1]) {
            cur.asc++;
            if (cur.asc > max.asc)
                max.asc = cur.asc;
        }
        else
            cur.asc = 1;

        //내림차순
        if (Numbers[i] <= Numbers[i - 1]) {
            cur.des++;
            if (cur.des > max.des)
                max.des = cur.des;
        }
        else
            cur.des = 1;
    }
    ans = max.asc > max.des ? max.asc : max.des;
    printf("%d\n", ans);

    return 0;
}