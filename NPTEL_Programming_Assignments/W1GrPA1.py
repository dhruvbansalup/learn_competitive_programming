# Problem Statement

# Rahul is looking for some special numbers. The numbers he is looking for should satisfy a specific constraint. The number, when prime factorized, should contain all prime factors of the same parity.
# Further, the number itself should be an even number.
# Help Rahul in identifying if a number is special or not.

# Prime Factorization:

# Prime factorization is the process of finding the prime numbers that multiply together to make a number. A prime number is a number that is greater than 1 and divided by 1 and itself only. The prime factorization of a number is the product of prime numbers that multiply together to make the original number. Every number has a unique prime factorization.

# Parity:

# Parity is a mathematical term that describes the property of an integer's inclusion in one of two categories: even or odd. An integer is even if it is 'evenly divisible' by 2, meaning it yields no remainder when divided by 2. An integer is odd if it is not even.

# Input Format

# The first line of input contains a single integer t, which is the number of test cases.
#  t test cases follow.
# Each test case consists of a single line containing a single integer n, which is the number to check.

# Constraints

# 		1≤t≤105

#  	       	1≤n≤260


# Output Format

# For each test case, print "YES" if the number is special, else print "NO".

# Sample Input

# 3
# 262623
# 124
# 131072


# Output

# NO
# NO
# YES

# Explanation

# Test Case 1:
# 262623 can be prime factorized as 3 x 87541
# The factors are of same parity, but the number itself is odd

# Test Case 2:
# 124 can be prime factorized as 2 x 2 x 31
# The number is even, However the factors 2 and 31 are of different parity.

# Test Case 3:

# all the prime factors are of the same parity, and the number itself is also even.


import math

def iseven(n):
    return n%2==0

def is_prime(n):
    if (n < 2):
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, math.floor(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def main():
    n=int(input())
    
    if not iseven(n):
        return "NO"
    if n==2:
        return "YES"
    
    factors=[]
    for i in range(2,n//2+1):
        if is_prime(i) and n%i==0:
            factors.append(i)
    
    if not factors:
        return "NO"
    
    parity=factors[0]%2
    
    for i in factors:
        if i%2!=parity:
            return "NO"
    return "YES"

T=int(input())
for _ in range(T):
    print (main())