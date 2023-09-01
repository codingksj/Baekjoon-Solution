def decode_rot13(cipher: str) -> str:
    msg = [get_new_ch(ch) for ch in cipher]
    
    return "".join(msg)

def get_new_ch(old : str) -> str:
    vowels = [
        "aiyeou",
        "AIYEOU",
    ]
    
    consonants = [
        "bkxznhdcwgpvjqtsrlmf",
        "BKXZNHDCWGPVJQTSRLMF"
    ]
    
    for vowel in vowels:
        if old in vowel:
            length = len(vowel)
            idx = (vowel.index(old) + 3) % length
            return vowel[idx]
    
    for consonant in consonants:
        if old in consonant:
            length = len(consonant)
            idx = (consonant.index(old) + 10) % length
            return consonant[idx]
    
    return old
    
while True:
    try:
        cipher = input()
        msg = decode_rot13(cipher)
        print(msg)
    except:
        break
