import sys, re

input = sys.stdin.readline

def chk(s : str):
    try:
        int(s)
        return True
    except ValueError:
        return False
    
def solve():
    polynomial = input().strip()
    monomials = polynomial.split(sep="x")
    diffrentiate = ""

    if(chk(polynomial)):
        diffrentiate = 0
    elif monomials[0] == "":
        diffrentiate = "1"
    elif monomials[0] == "-":
        diffrentiate = "-1"
    else:
        diffrentiate = monomials[0]

    print(diffrentiate)
    
def main():
    solve()

if __name__ == "__main__":
    main()
