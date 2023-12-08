n = int(input())

words : set[str] = set()

for i in range(n):
    word = input()
    words.add(word)
    if word[::-1] in words:
        print(f"{len(word)} {word[len(word)//2]}")
        break