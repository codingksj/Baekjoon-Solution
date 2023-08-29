def find_max_paper(rows : list[int], cols : list[int]) -> int:
    lengthR = len(rows)
    lengthC = len(cols)
    
    d_rows = [rows[i]-rows[i-1] for i in range(1, lengthR)]
    d_cols = [cols[i]-cols[i-1] for i in range(1, lengthC)]
    
    paper = max(d_rows) * max(d_cols)
    
    return paper
    
r, c = map(int, input().split())
rows : list[int] = [0, r]
cols : list[int] = [0, c]
tc = int(input())

for _ in range(tc):
    rc, lineNum = map(int, input().split())
    if rc:
        rows.append(lineNum)
    else:
        cols.append(lineNum)

rows.sort()
cols.sort()

paper = find_max_paper(rows, cols)

print(paper)