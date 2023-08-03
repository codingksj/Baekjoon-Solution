#include<stdio.h>
int main(){
    int N;
    int blank = 0;
    scanf("%d",&N);
    for(int i=N;i>0;i--){
        for(int j=0;j<N;j++){
            if(j<blank){
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        blank++;
        printf("\n");
    }
    return 0;
}