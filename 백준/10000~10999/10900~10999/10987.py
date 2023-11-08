vowels = "aeiou"
word = input()
count = sum(word.count(vowel) for vowel in vowels)

print(count)
