#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100001
#define MAX_NAME 101

struct Member {
    int age;
    int order;
    char name[MAX_NAME];
};

struct Member member[MAX_N];

int cmp(const void* a, const void* b) {
    struct Member* mem1 = (struct Member*)a;
    struct Member* mem2 = (struct Member*)b;

    if (mem1->age == mem2->age) {
        return mem1->order - mem2->order;
    }
    else {
        return mem1->age - mem2->age;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &member[i].age, member[i].name);
        member[i].order = i; 
    }

    qsort(member, n, sizeof(member[0]), cmp);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", member[i].age, member[i].name);
    }

    return 0;
}
