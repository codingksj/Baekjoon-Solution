def count_unique_substrings(s):
    n = len(s)
    unique_substrings = set()

    for length in range(1, n + 1):
        for i in range(n - length + 1):
            substring = s[i:i + length]
            unique_substrings.add(substring)

    return len(unique_substrings)

input_string = input()
result = count_unique_substrings(input_string)
print(result)
