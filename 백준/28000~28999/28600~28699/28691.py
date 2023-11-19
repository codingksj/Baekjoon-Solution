clubs : list[str] = ["MatKor", "WiCys", "CyKor", "AlKor", "$clear"]

first = input()

for club in clubs:
    if club[0] == first:
        print(club)
        break