START = 1
END = 6
x = [0]
for i in range(START, END+1):
    line = input()
    x.append(len(line.rstrip()))

print(f"Latitude {x[1]}:{x[2]}:{x[3]}")
print(f"Longitude {x[4]}:{x[5]}:{x[6]}")