#code
t=int(input())
while(t):
    n=int(input())
    A=list(map(int,input().split()))
    s=[]
    nge=[-1]*n
    if(n==1):
        print(-1)
        continue
    s.append(0)
    for  i in range(1,n):
        while(len(s)>0 and A[s[-1]]<A[i]):
            nge[s.pop()]=A[i]
        s.append(i)
    
    for a in nge:
        print(a,end=" ")
    print()
    t-=1