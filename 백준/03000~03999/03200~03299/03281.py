def convert_word(word : str) -> list[int]:
    tele : dict[int:str] = {
        1:" ", 2:"ABC", 3:"DEF",
        4:"GHI",5:"JKL",6:"MNO",
        7:"PQRS",8:"TUV",9:"WXYZ",
    }
    
    num_list = []
    for ch in word:
        for k,v in tele.items():
            if ch in v:
                num_list.append(k)
                
    return num_list
                
tc = int(input())

words_dict : dict[str:list[int]] = {}

for i in range(tc):
    word = input()
    words_dict[word] = convert_word(word)
     
length = int(input())
line = input()
cipher_list = [list(map(int, part.split())) for part in line.split("1")]

ans = []

for cipher in cipher_list:
    matching_word = next((k for k, v in words_dict.items() if cipher == v), None)
    if matching_word:
        ans.append(matching_word)
    else:
        ans.append("*" * len(cipher))

print(*ans)