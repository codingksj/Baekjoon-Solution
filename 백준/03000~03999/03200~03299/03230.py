n, m = map(int, input().split())

first_race = []
second_race = []

for i in range(1,n+1):
    rank = int(input())
    first_race.insert(rank-1, i) 

for i in range(m-1,-1,-1):
    rank = int(input())
    second_race.insert(rank-1, first_race[i])

for i in range(3):
    print(second_race[i])
