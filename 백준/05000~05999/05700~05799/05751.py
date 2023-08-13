while True:
    test = int(input())
    if test == 0:
        break
    game = input()
    count0 = game.count("0")
    count1 = game.count("1")
    print(f"Mary won {count0} times and John won {count1} times")
    
