TC = int(input())
for i in range(TC):
    bits = input()
    mid = len(bits)//2
    doit = bits[mid-1] == bits[mid]
    print("Do-it" if doit else "Do-it-Not")