test = int(input())

telephone = ["---","---","ABC","DEF","GHI",
             "JKL","MNO","PQRS","TUV","WXYZ"]

for i in range(test):
    word = input()
    pelindrome = ""
    reversed_pelindrome = ""
    word = word.upper()
    for letter in word:
        for index, alpha in enumerate(telephone):
            if letter in alpha:
                pelindrome+=str(index)
    
    reversed_pelindrome = "".join(reversed(pelindrome))
    print("YES" if pelindrome == reversed_pelindrome else "NO")
    
    