promises : list[str] = [
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop"
]

n : int = int(input())
is_promise : bool = True

for i in range(n):
    sentence = input()
    if sentence not in promises:
        is_promise = False
        
print("Yes" if not is_promise else "No")