while True:
    N, D = map(int, input().split())
    if N == 0 and D == 0:
        break
    
    sum_of_col = [0]*N
    for i in range(D):
        attendees = list(map(int, input().split()))
        for j in range(N):
            sum_of_col[j] += attendees[j]
    
    attended_all = True if D in sum_of_col else False
    print("yes" if attended_all else "no")
