banned_word = set("CAMBRIDGE")

word = input()
answer_list = []

for letter in word:
    if letter not in banned_word:
        answer_list.append(letter)

answer = ''.join(answer_list)
print(answer)
