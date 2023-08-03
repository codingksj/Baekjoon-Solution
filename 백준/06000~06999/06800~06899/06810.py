isbn = "9780921418"
for i in range(3):
    digit = input()
    isbn+=digit

sum = 0
for i, digit in enumerate(isbn):
    if i%2 == 0:
        sum += int(digit)
    else:
        sum += int(digit)*3

print(f"The 1-3-sum is {sum}")