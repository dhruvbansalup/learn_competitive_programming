# Arya and Bran are playing a game
# Initially, two positive integer A and B are written on a blackboard
# The payers take turns, starting with Arya.
# On his or her turn, a player can replace A with A-kB or B with B-kA for andy positive integer k
# The first person to make one of thr number drop to zero or below loses.


# Ww will say (A,B) is a winning position if the person who plays first will win the game, and (A,B) is a losing position if the person who plays first will lose the game. No matter how the players play, they will play optimally.

# You have to find out if (A,B) is a winning position or a losing position.

# Given 4 int 
# 1 <= A1 <= A2 ;B1 <= B2 <= 10^6
# count how many winning positions (A,B)

# (A,B) is a winning possition if and only if A>=phi*B where phi is the golden ratio (1+sqrt(5))/2 = 1.61...

import math
golden=(1+5**0.5)/2

def main():
    a1,a2,b1,b2=list(map(int,input("a1 a2 b1 b2: ").strip().split()))

    ans=0
    for b in range(b1,b2+1):
        if(a1>golden*b or (golden-1)*b>a2):
            ans+=(a2-a1+1)
        else:
            ans+=max(0,(a2-math.floor(golden*b)))
            ans+=max(0,(math.floor((golden-1)*b)-a1+1))
    print(ans)
main()