tc = int(input())
win = 0
for i in range(tc):
    skills = input()
    if "CD" not in skills:
        win+=1
print(win)
    