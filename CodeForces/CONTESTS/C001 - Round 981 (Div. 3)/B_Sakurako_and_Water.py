cases=int(input())
for case in range(cases):
    n=int(input())
    m=[]
    for row in range(n):
        row=input()
        row=row.strip().split()
        row=[int(i) for i in row]
        m.append(row)

    magic=[0 for i in range(2*n-1)]

   
    for d in range(1,len(magic)+1): # Go through all diagonals
        if d<=n:
            for r in range(d):
                    if m[r][n-d+r]<0:
                        magic[d-1]=min(m[r][n-d+r],magic[d-1])
        else:
            D=d-n
            for r in range(D):
                    if m[(n-1)-r][D-r-1]<0:
                        magic[d-1]=min(m[(n-1)-r][D-r-1],magic[d-1])
    print(abs(sum(magic)))
