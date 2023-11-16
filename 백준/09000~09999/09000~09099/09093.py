def reverse_word_in_sentence(sentence: str) -> str:
    words: list[str] = sentence.split()
    reversed_words: list[str] = list(word[::-1] for word in words)
    reversed_sentence: str = ' '.join(reversed_words)
    return reversed_sentence

n = int(input())

for i in range(n):
    sentence = input()
    rev_sentence = reverse_word_in_sentence(sentence)
    print(rev_sentence)