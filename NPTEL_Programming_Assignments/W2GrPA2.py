# During the pandemic era of 2020, Chennai faced a severe outbreak of COVID-19. A citywide lockdown was imposed, restricting people from leaving their homes. To ensure citizens had access to essential supplies like food and medicine, the State Government of Chennai devised a plan to use drones for contactless delivery, maintaining strict social distancing protocols.

# Each drone has a fixed carrying capacity, represented as an integer in the array capacities , and all drones are identical in functionality apart from their carrying capacity. To optimize the delivery process and minimize resource wastage, the government aims to select exactly x
#  drones such that each of these x
#  drones has a carrying capacity of at leastx
#  . This selection process ensures the fleet's efficiency aligns with the demand for heavier deliveries.

# Your task is to determine the "critical capacity" x
#  , such that exactly x
#  drones can meet this x
# criterion. If no such x
#  exists, return −1
#  . It is guaranteed that if a "critical capacity" exists, it will be unique

# Input Format

# The first line of the input contains a single integer t, representing the number of test cases.
# For each test case, the input consists of two lines:
# The first line contains a single integer n
# , the length of the array.
# The second line contains $n$ space-separated positive integers, representing the array capacities.


# Constraints
# 1≤t≤105
# 1≤n≤105.
# 1≤capacities[i]≤1015.


# Output Format :
# Return the integer x
#  if a "critical capacity" exists; otherwise, return −1
# .

# Example

# Sample Input 1

# 3
# 2
# 3 5
# 5
# 3 5 6 1 2
# 3
# 1 1 3


# Output

# 2
# 3
# -1


# Explanation
# There are 2
#  drones (capacities 3
#  and 5
# ) with carrying capacities of at least 2
# .

# and

# There are 3
#  drones (capacities 3
# , 5
#  and 6
# ) with carrying capacities of at least 3
# .

# and

# For x=0
# , there should be 0
#  drones capable of carrying at least 0
# , but there are 3
# .
#  For x=1
# , there should be 1
#  drone capable of carrying at least 1
# , but there are 3
# .
#  For x=2
# , there should be 2
#  drones capable of carrying at least2
# , but there are 1
# .
#  For x=3
# , there should be 3
#  drones capable of carrying at least3
# , but there are1
# . Thus, no valid x
#  exists.


# #Brute Force
# def main(l,capacities):
#     if l==0:
#         return 0
    
#     for i in range(1,l+1):
#         capable=0
#         for j in range(l):
#             if capacities[j]>=i:
#                 capable+=1
#         if capable==i:
#             return i
    
#     return -1

#optimized
def main(l,capacities):
    if l==0:
        return 0
    capacities.sort(reverse=True)
    for i in range(1,l+1):
        if i<l:
            if capacities[i]<i and capacities[i-1]>=i:
                return i
        elif capacities[i-1]>=i:
            return i
    return -1

T=int(input())
for _ in range(T):
    l=int(input())
    capacities=list(map(int,input().strip().split(" ")))

    print(main(l,capacities))