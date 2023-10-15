num_cards = {'P':13, 'K':13, 'H':13, 'T':13}
card_set = set()
is_same = False

s = input()

for i in range(0, len(s), 3):
    card = s[i:i+3]
    if card in card_set :
        is_same = True
        print('GRESKA')
        break
    card_set.add(card)
    num_cards[s[i]] -= 1

if not is_same:
    print(*num_cards.values())