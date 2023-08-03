#include <stdio.h>
#include <string.h>

int main(){
    int index;
    char input[3];
    
    char grade[13][3] = {
        "A+","A0","A-",
        "B+","B0","B-",
        "C+","C0","C-",
        "D+","D0","D-",
        "F"
    };
    double score[13] = {
        4.3,4.0,3.7,
        3.3,3.0,2.7,
        2.3,2.0,1.7,
        1.3,1.0,0.7,
        0.0
    };
    scanf("%s", input);
    for(int i=0;i<13;i++){
        if(!strcmp(input, grade[i])){
            index = i;
            break;
        }
    }
    printf("%.1f\n",score[index]);
    return 0;
}
