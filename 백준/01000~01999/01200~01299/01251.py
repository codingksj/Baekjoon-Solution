def find_lexical_first(word : str) -> str:
    words = []
    max_length = len(word)
    
    for i in range(1,max_length-1):
        part1 = "".join(reversed(word[:i]))
        for j in range(i+1, max_length):
            part2 = "".join(reversed(word[i:j]))
            part3 = "".join(reversed(word[j:]))
            new_word = part1 + part2 + part3
            words.append(new_word)
    
    words.sort()
    
    return words[0]
    
word = input()
first_word = find_lexical_first(word)
print(first_word)
        
    