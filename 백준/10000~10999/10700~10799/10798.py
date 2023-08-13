words = []
maxL = -1
for i in range(5):
    word = input()
    words.append(word)
    if maxL < len(word):
        maxL = len(word)
    
for i in range(maxL):
    for n in range(5):
        if i<len(words[n]):
            print(words[n][i], end="")