#include <stdio.h>
#include <stdbool.h>

char alpha[26];

int main() {
    int TC;

    char name[31];
    char first;

    bool CanGame = false;
    
    scanf("%d",&TC);
    
    while (TC--) {
        scanf("%s", name);
        first = name[0] - 'a';
        alpha[first]++;
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] >= 5) {
            CanGame = true;
            printf("%c", ('a'+i));
        }
    }
    if (!CanGame) {
        printf("PREDAJA\n");
    }
    return 0;
}
