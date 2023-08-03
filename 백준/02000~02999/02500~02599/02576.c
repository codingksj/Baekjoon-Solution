#include <stdio.h>
#include <stdbool.h>

int main() {
    bool HasOdd = false;

    int input;
    int min_odd = 101;
    int sum = 0;

    for (int i = 0; i < 7; i++) {
        scanf("%d", &input);
        if (input & 1) {
            sum += input;
            HasOdd = true;
            min_odd = input < min_odd ? input : min_odd;
        }
    }
    HasOdd ? printf("%d\n%d\n", sum, min_odd) : printf("-1\n");
    return 0;
}
