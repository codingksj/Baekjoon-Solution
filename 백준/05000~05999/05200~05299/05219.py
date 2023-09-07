def get_rule(line: str) -> list[list[str]]:
    words = line.split()
    rules = [words[i:i+2] for i in range(0, len(words), 2)]
    return rules

def decrypt_msg(rules: list[list[str]], msg: str) -> str:
    seps_msgs = list(msg.split())
 
    for k, v in rules:
        for i in range(len(seps_msgs)):
            seps_msgs[i] = seps_msgs[i].replace(k, v, 1)
            
    decrypted_msg = " ".join(s for s in seps_msgs).strip()
    
    return decrypted_msg

tc = int(input())

for _ in range(tc):
    rules = get_rule(input())
    msg = input()
    transformed_msg = decrypt_msg(rules, msg)
    print(f"Transformed strings: {transformed_msg}")
