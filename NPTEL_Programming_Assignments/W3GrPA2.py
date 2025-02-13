# Critical Drone Allocation II

# Following the implementation of the drone delivery system in Chennai during the pandemic, the government is now focusing on further optimizing the delivery process. With the increasing demand for essential supplies, the government wants to ensure that the maximum number of households can be served efficiently.

# Each household has a specific minimum delivery requirement h[i]
# , representing the minimum load a drone must carry to fulfill the household's needs. The fleet consists of drones, each with a carrying capacity d[j]
# . A drone can be assigned to a household only if its carrying capacity meets or exceeds the household's requirement. Additionally, each drone can only be used for one household.

# Your task is to determine the maximum number of households that can be served by the available drones while adhering to these constraints. If no household can be served by any drone, the output for that test case should be 0
# .

# Input Format

# The first line of the input contains a single integer t
# , representing the number of test cases.
# For each test case, the input consists of three lines:
# The first line contains two integers m
#  and n
#  — the number of households and the number of drones, respectively.
# The second line contains m
#  space-separated positive integers h[1],h[2],⋯,h[m]
#  — the minimum delivery requirements for the households.
# The third line contains n
#  space-separated positive integers d[1],d[2],⋯,d[n]
#  — the carrying capacities of the drones.


# Constraints

# 1≤t≤105
# 1≤h.length (m)≤105
# .
# 1≤d.length (n)≤105
# .
# 1≤h[i],d[i]≤1015
# .


# Output Format

# For each test case, output a single integer on a new line — the maximum number of households that can be served.

# Example

# Sample Input 1

# 2
# 3 3
# 10 15 20
# 5 10 15
# 3 3
# 5 10 15
# 15 20 25


# Output
# 2
# 3

# Explanation

# There are 3
#  households with minimum delivery requirements of 10,15,
#  and 20
# . The fleet has 3
#  drones with carrying capacities of 5,10,
#  and 15
# . Only the first two households can be served as the third household's requirement exceeds the capacities of all drones.
#  Thus, the output is 2
# .

# and

# There are 3
#  households with minimum delivery requirements of 5,10,
#  and 15
# . The fleet has 3
#  drones with carrying capacities of 15,20, and 25
# . All households can be served by assigning drones appropriately.
#  Thus, the output is 3.



def main(m,n,h,d):
    h.sort()
    d.sort()

    count=0

    prev=0
    for i in range(m):
        for j in range(prev,len(d)):
            if h[i]<=d[j]:
                count+=1
                del d[j]
                prev=j
                break
    print(count)

T=int(input())
for _ in range(T):
    m,n=map(int,input().strip().split(' '))
    h=list(map(int,input().strip().split(" ")))
    d=list(map(int,input().strip().split(" ")))

    main(m,n,h,d)


