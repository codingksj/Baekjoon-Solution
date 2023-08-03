burgers = []
drinks = []
sets = []
for i in range(3):
    burger = int(input())
    burgers.append(burger)
for i in range(2):
    drink = int(input())
    drinks.append(drink)
    
for burger in range(3):
    for drink in range(2):
        sets.append(burgers[burger]+drinks[drink]-50)

print(min(sets))
    