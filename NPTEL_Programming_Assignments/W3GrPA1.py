# You are a hobbit living in the Shire. You live a peaceful life in your house. However, one day you are visited by a wizard who tells you that you are the chosen one to destroy the ring of power. The ring is located in the Mordor, a land far away from the Shire. The wizard gives you a map of the Mordor. You map out your path to Mordor from the Shire; however, the path is long and tiring. To ease your trip planning, you break the journey into checkpoints.

# Each checkpoint also has a few refreshments for you to replenish your energy. However, you can choose to skip stopping at a checkpoint if you have enough energy to reach the next checkpoint. If you stop at a checkpoint, you take a nap and spend any remaining energy you have and restart your journey the next day with as much energy as available in that checkpoint.

# You are given a list of n
#  integers which represents the amount of energy each of the n
#  checkpoints will provide you if you rest there. You need x
#  amount of energy to go from any checkpoint to the next checkpoint. The first checkpoint is the Shire and the last checkpoint is the Mordor.

# Find out whether you can reach the Mordor from the Shire or not.

# Input Format

# The first line of input contains a single integer t
# , which represents the number of test cases.
# Each test case consists of two lines.
# The first line contains two space separated integers n
#  and x
# . n
#  is the number of checkpoints and x
#  is the amount of energy required to go from any checkpoint to the next checkpoint. The next line contains n
#  space separated integers a1,a2,a3,…,an
#  which represents the amount of energy each of the n
#  checkpoints will provide you if you rest there

# Constraints

# 1≤t≤103
# 1≤n≤103
# 1≤x≤103
# 1≤ai≤1015 ∀i∈[1,n]

# Output Format

# For each test case, print "YES" if you can reach the Mordor from the Shire, otherwise print "NO".

# Example

# Sample Input 1
# 2
# 5 2
# 4 6 2 1 8
# 5 3
# 9 7 4 2 13


# Output

# YES
# NO

# Explanation

# Test Case 1

# As each move to the adjacent checkpoint requires 2 energy, we can move from checkpoint 1 to 2 or 3.
# If we move to checkpoint 2, we can then move to checkpoint 3, 4, and 5.
# Checkpoint 5 is the last checkpoint, so we can reach the Mordor.

# Test Case 2

# From the checkpoint 1, we can move to checkpoint 2, 3, or 4.
# From the checkpoint 2, we can move to checkpoint 3 or 4.
# From the checkpoint 3, we can move to checkpoint 4.
# From the checkpoint 4, we cannot move anywhere as we do not have enough energy to move to the next checkpoint.
# In the end, we get stuck at checkpoint 4 and cannot reach the Mordor.


def main(n,step,v):
    reachable=[0]*n
    reachable[0]=1
    
    for i in range(n):
        if reachable[i]==0 or reachable[-1]==1:
            break
        limit=v[i]//step
        
        for j in range(min(i+limit,n-1),i,-1):
            if reachable[j]==1:
                break
            reachable[j]=1
    
    return reachable[-1]


T=int(input())
for _ in range(T):
    n, step=map(int, input().strip(). split(" "))
    v=list(map(int, input().strip().split(' ')))
    if main(n, step,v):
        print("YES")
    else:
        print("NO")
    