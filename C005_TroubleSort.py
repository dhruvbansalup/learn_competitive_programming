# TroubleSort or Triplet Bubble Sort

#Trouble Sort can fail

def TroubleSort(L):
    done=False
    while not done:
        done=True
        for i in range(len(L)-2):
            if L[i]>L[i+2]:
                done=False
                # Reverse sublist
                L[i],L[i+1],L[i+2]=L[i+2],L[i+1],L[i]
    return L

def Faster_TroubleSort(L):
    # Trouble Sort is bubble sort for odd and even sub array of the main array
    odd=L[::2]
    even=L[1::2]
    odd=sorted(odd)
    even=sorted(even)

    for i in range(len(L)):
        if i%2!=0:
            L[i]=even.pop(0)
        else:
            L[i]=odd.pop(0)
    return L

print(TroubleSort([5,3,2,8]))
print(Faster_TroubleSort([5,3,2,8]))
    