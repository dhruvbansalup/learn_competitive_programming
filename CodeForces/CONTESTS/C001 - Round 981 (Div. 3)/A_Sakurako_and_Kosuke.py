cases=int(input())
for case in range(cases):
    n=int(input())
    
    # #Method -1
    # x=0
    # i=0
    # while True:
    #     i+=1
    #     #Sakurako turn
    #     x-=(2*i)-1
    #     if abs(x)>n:
    #         print("Sakurako")
    #         break
        
    #     i+=1
    #     #Kosuke turn
    #     x+=(2*i)-1
    #     if abs(x)>n:
    #         print("Kosuke")
    #         break

    #Method -2
    if  n%2==1:
        print("Kosuke")
    else:
        print("Sakurako")