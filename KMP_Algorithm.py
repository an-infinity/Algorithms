#Count number of occurrences of pattern in text in O(1) complexity
def lpsarr(p):
    n=len(p)
    l=[0]*n
    i,j=1,0
    while(i<n):
        if(p[i]==p[j]):
            l[i]=j+1
            j+=1
            i+=1
        else:
            if(j==0):
                i+=1
            else:
                j=l[j-1]
    return l

def KMP(p,t):
    lps=lpsarr(p)
    i,j,c=0,0,0
    while(i<len(t)):
        if(t[i]==p[j]):
            i+=1
            j+=1
        if(j==len(p)):
            c+=1
            j=lps[j-1]
        elif(i<len(t) and t[i]!=p[j]):
            if(j==0):
                i+=1
            else:
                j=lps[j-1]
    return c
p=input()
t=input()
print(KMP(p,t))
