def plural(s):
    return s[:-2]+"i"


T=int(input())
for _ in range(T):
    singular=input()
    print(plural(singular))