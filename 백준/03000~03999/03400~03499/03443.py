ROCK = 1
SCISSORS = 2
PAPER = 3

rsp_dict = {
    "Kamen": ROCK, "Rock": ROCK, "Pierre": ROCK, "Stein": ROCK, "Ko": ROCK, "Koe": ROCK, "Sasso": ROCK, "Roccia": ROCK, "Guu": ROCK, "Kamien": ROCK, "Piedra": ROCK,
    "Nuzky": SCISSORS, "Scissors": SCISSORS, "Ciseaux": SCISSORS, "Schere": SCISSORS, "Ollo": SCISSORS, "Olloo": SCISSORS, "Forbice": SCISSORS, "Choki": SCISSORS, "Nozyce": SCISSORS, "Tijera": SCISSORS,
    "Papir": PAPER, "Paper": PAPER, "Feuille": PAPER, "Papier": PAPER, "Carta": PAPER, "Rete": PAPER, "Paa": PAPER, "Papier": PAPER, "Papel": PAPER
}

def calculate_scores(game_results : list[str]):
    player1_score = 0
    player2_score = 0

    for game in game_results:
        p1, p2 = game.split()
        hand1 = rsp_dict.get(p1)
        hand2 = rsp_dict.get(p2)

        if (hand1 == ROCK and hand2 == SCISSORS) or (hand1 == SCISSORS and hand2 == PAPER) or (hand1 == PAPER and hand2 == ROCK):
            player1_score += 1
        elif (hand2 == ROCK and hand1 == SCISSORS) or (hand2 == SCISSORS and hand1 == PAPER) or (hand2 == PAPER and hand1 == ROCK):
            player2_score += 1

    return player1_score, player2_score

game_count = 1

while True:
    nation1, player1 = input().split()
    nation2, player2 = input().split()
    
    game_results : list[str] = []

    while True:
        game = input()
        if game == "-" or game == ".":
            break

        game_results.append(game)

    player1_score, player2_score = calculate_scores(game_results)

    print(f"Game #{game_count}:")
    print(f"{player1}: {player1_score} {'points' if player1_score != 1 else 'point'}")
    print(f"{player2}: {player2_score} {'points' if player2_score != 1 else 'point'}")

    if player1_score == player2_score:
        print("TIED GAME")
    elif player1_score > player2_score:
        print(f"WINNER: {player1}")
    else:
        print(f"WINNER: {player2}")

    game_count += 1
    print()
    
    if game == ".":
        break
