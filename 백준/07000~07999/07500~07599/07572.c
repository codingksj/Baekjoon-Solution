#include <stdio.h>

int main() {
    int animals[12] = { 'I','J','K','L','A','B','C','D','E','F','G','H' };
    int gans[10] = { 6,7,8,9,0,1,2,3,4,5 };
    int animal, gan;
    int year;

    scanf("%d", &year);

    gan = gans[year % 10];
    animal = animals[year % 12];

    printf("%c%d", animal, gan);
    return 0;
}
