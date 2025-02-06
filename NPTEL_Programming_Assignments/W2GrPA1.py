# You are the sports teacher of a school. There are n
#  students in your class. You ask the students to stand in a line according to their heights. They then run laps on a circular ground while still maintaining the same order. After an arbitrary number of laps, you ask the students to stand in a line again. However, now some students might have done one more lap than the others and thus have moved ahead of the others. Their circular order is still maintained.

# However, as the ground is pretty big, you suspect a particular student might be missing. You are given the heights of the students in the current order, and the height of the target student. Find if the target student is present in the queue.

# Input Format

# The first line of input contains a single integer t
# , denoting the number of test cases.
# Each test case consists of two lines.
# The first line of each test case contains two integers n
#  and x
# , denoting the number of students and the height of the target student.
# The second line of each test case contains n
#  integers a1,a2,....,an
# , denoting the heights of the students in the current order.


# Constraints
# 1≤t≤103

# 1≤n≤103

# 1≤x,ai≤1015

# ai=aj⟹i=j


# Output Format
# For each test case, print the index of the target student in the current order.
# If the target student is not present, print -1.

# Example

# Sample Input

# 2
# 7 9
# 4 5 6 7 9 1 2
# 7 3
# 4 5 6 7 8 1 2


# Output:

# 4
# -1


# Explanation
# 0 is present at index 4 in the first test case.
# 3 is not present in the second test case.


T=int(input())
for _ in range(T):
    n,h=map(int,input().strip().split(" "))
    heights=list(map(int,input().strip().split(" ")))
    
    try:
        i=heights.index(h)
    except:
        i=-1

    print(i)