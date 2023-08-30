def get_ranks(players : dict[int:str]) -> list[int]:
    ranks : list[int] = [0 for _ in range(9)]
    distances : list[int] = []
    
    for index, player in players.items():
        distances.append(player.find(str(index)))
    
    sorted_distances = sorted(list(set(distances)), reverse=True)
    
    rank = 1
    
    for sd in sorted_distances:
        for i in range(9):
            if not ranks[i] and sd == distances[i]:
                ranks[i] = rank
                distances[i] = -1
                
        rank += 1
    
    return ranks

r, c = map(int, input().split())

pattern = "123456789"

players : dict[int:str] = {}

for _ in range(r):
    line = input()
    for digit in pattern:
        if digit in line:
            players[int(digit)] = line
            break

players = dict(sorted(players.items()))
ranks = get_ranks(players)

for rank in ranks:
    print(rank)