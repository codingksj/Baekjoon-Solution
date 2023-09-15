def check_cycle_same(wordSet: list[str],
                     word : str) -> bool:
    
    length = len(word)
    
    for i in range(length):
        rotate_word = word[i:] + word[:i]
        if rotate_word in wordSet:
            return True
        
    return False

n = int(input())

wordSet : list[str] = []

for _ in range(n):
    word : str = input()
    if not check_cycle_same(wordSet, word):
        wordSet.append(word)

ans = len(wordSet)

print(ans)