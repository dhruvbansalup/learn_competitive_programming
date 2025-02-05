N=int(input())#No of Frinds
position=list(map(int,input().strip().split(" ")))
speed=list(map(int,input().strip().split(" ")))

def CanMeetInTime(t):
    high=[(position[i]+(speed[i]*t)) for i in range(N)]
    low=[(position[i]-(speed[i]*t)) for i in range(N)]

    rightmostLeftEndPoint=max(low)
    leftmostRightEndPoint=min(high)
    
    return rightmostLeftEndPoint<=leftmostRightEndPoint

LowerT=0
HeigherT=(max(position)-min(position))/min(speed)

while (HeigherT-LowerT>(10**-6)):
    midT=(HeigherT+LowerT)/2

    if CanMeetInTime(midT):
        HeigherT=midT
    else:
        LowerT=midT
    
print(midT)