import sys

input = sys.stdin.readline

def row_check(r : int, num : int) -> bool:
    for i in range(9):
        if num == sudoku[r][i]: 
            return False
    return True

def col_check(c : int, num : int) -> bool:
    for i in range(9):
        if num == sudoku[i][c]: 
            return False
    return True

def square_check(r : int, c : int, num : int) -> bool:
    for i in range(3):
        for j in range(3):
            sr = (r//3) * 3 + i
            sc = (c//3) * 3 + j
            if num == sudoku[sr][sc]:
                return False
    return True

def solve_sudoku(depth : int):
    if depth == len(blanks):
        for row in sudoku:
            print(*row)
        exit()
        
    for num in range(1, 10):
        r, c = blanks[depth]
        if col_check(c, num) and row_check(r, num) and square_check(r, c, num):
            sudoku[r][c] = num
            solve_sudoku(depth+1)
            sudoku[r][c] = 0

sudoku = [list(map(int, input().split())) for _ in range(9)]
blanks = []

for r in range(9):
    for c in range(9):
        if sudoku[r][c] == 0:
            blanks.append([r, c])

solve_sudoku(0)
