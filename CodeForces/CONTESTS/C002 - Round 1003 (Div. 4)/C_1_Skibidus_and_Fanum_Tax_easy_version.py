#Getting a error on submittion 2

def canBeSorted(n,m,a,b):
    a[0]=min(a[0],b-a[0])
    for i in range(1,n):
        if a[i-1]>a[i]: #Incorrect
            if a[i-1]>b-a[i]: #Can Not Be corrected
                return False
            else:# Can corrected
                a[i]=b-a[i]
        else: #Correct
            if a[i-1]<=b-a[i]: #can decrease
                a[i]=b-a[i]
    return True


T=int(input())
for _ in range(T):
    n,m=map(int,input().strip().split(" "))
    a=list(map(int,input().strip().split(" ")))
    b=int(input())
    if (canBeSorted(n,m,a,b)):
        print("YES")
    else:
        print("NO")