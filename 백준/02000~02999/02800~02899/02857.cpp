FBI_list = []
for i in range(1,6):
    isFBI = True
    fbi = input()
    if "FBI" in fbi:
        FBI_list.append(i)

if FBI_list != []:
    for n in FBI_list:
        print(n, end=" ")
else:
    print("HE GOT AWAY!")

            