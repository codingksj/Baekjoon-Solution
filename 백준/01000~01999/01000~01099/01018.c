#include<stdio.h>
#include<string.h>

int main() {
	char boardW[8][8] = {
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	};
	char boardB[8][8] = {
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'}
	};
	char board[51][51] = { 0, };
	int Bcnt = 0, Wcnt = 0, cnt = 0;
	int i, j;
	int r, c;
	int N, M;
	int min = 65;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", &board[i]);
	}

	//처음 ~ 8*8 검사 가능할때까지
	for (i = 0; i <= N - 8; i++) {
		for (j = 0; j <= M - 8; j++) {
			Bcnt = 0;
			Wcnt = 0;
			//판 검사
			for (r = 0; r < 8; r++) {
				for (c = 0; c < 8; c++) {
					if (boardB[r][c] != board[r + i][c + j])
						Bcnt++;
					if (boardW[r][c] != board[r + i][c + j])
						Wcnt++;
				}
			}
		
			if (Bcnt < min)
				min = Bcnt;
			if (Wcnt < min)
				min = Wcnt;
		}
	}
	printf("%d", min);

	return 0;
}