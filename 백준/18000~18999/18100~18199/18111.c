#include <stdio.h>

int blocks[501][501];

typedef struct answer_ {
    int time;
    int height;
}Answer;

typedef struct size_ {
    int rows;
    int cols;
}Size;

void GetDeltaBlock(Answer* answer, Size* size, int height, int B) {
    int delta = 0;
    int N = size->rows;
    int M = size->cols;
    int min_time = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            delta = blocks[i][j] - height;
            if (delta > 0) {
                min_time += (delta * 2);
            }
            else if (delta < 0) {
                min_time -= (delta);
            }
            B += delta;
        }
    }
    if (B >= 0) {
        if (min_time < answer->time) {
            answer->time = min_time;
            answer->height = height;
        }
    }

}

int main(){
    int N, M, B;
    int min = 256, max = 0;
    Answer answer = {13*10000000, 0};
    Size size = { 0,0 };
    scanf("%d %d %d", &N, &M, &B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &blocks[i][j]);
            min = min < blocks[i][j] ? min : blocks[i][j];
            max = max > blocks[i][j] ? max : blocks[i][j];
        }
    }
    size.rows = N;
    size.cols = M;
    
    for (int height = max; height >= min; height--) {
        GetDeltaBlock(&answer, &size, height, B);
    }
    printf("%d %d", answer.time, answer.height);
    return 0;
}