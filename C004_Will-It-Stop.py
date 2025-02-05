# Given the following code:
# while n>1 do 
# if n mod 2 = 0 then
# n:=n / 2
# else
# n:=3*n+3

# the integer n bw 2 and 10^14
# return Yes if the program will stop, otherwise return No

# A power of 2 : Terminates Eventually

n=int(input())

if (n^n-1)&n ==n:
    print ("YES")
else:
    print("NO")