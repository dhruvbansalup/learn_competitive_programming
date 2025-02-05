# Reversort Engineering
# Given N and C, we need to construct an initial permutation that will result in exactly C cost when applying Reversort.


def construct(N,C,M):
    if (N==1):
        return str(M)
    else:
        if C-1>=N-2 and C-1<=(N*(N-1)/2)-1:
            return str(M)+" " + construct(N-1,C-1,M+1)
        else:
            deltaCost=int(C-((N*(N-1)/2)+1))
            y=construct(N-1,C-deltaCost,M+1)
            
            smallarr=y.split(" ")
            newarr=[str(M)]
            newarr.extend(smallarr)

            ans=" ".join(newarr[:deltaCost][::-1]+newarr[deltaCost:])
            return ans

def main():
    T=int(input("No of Test Cases: "))

    for case in range(1,T+1):
        N,C=list(map(int,input("no_of_element cost: ").strip().split())) # N is the number of elements in the list and C is the cost

        if C<N-1 or C>(N*(N-1)/2)-1:
            print("Case #" + str(case)+": IMPOSSIBLE")
        else:
            A=construct(N,C,1) 
            print("Case #"+str(case)+": "+A)

if __name__=="__main__":
    main()