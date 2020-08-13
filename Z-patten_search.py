#code
def Zarr(s):
    n=len(s)
    l,r=0,0
    z=[0]*n
    for i in range(1,n):
        z[i]=max(0,min(z[i-l],r-i+1))
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]):
            l=i
            r=i+z[i]
            z[i]+=1
    return z

t=int(input())
while(t):
    text=input()
    pat=input()
    s=pat+'$'+text
    z=Zarr(s)
    x=len(pat)
    flag=0
    for i in range(len(s)):
        if(z[i]==x):
            flag=1
            break
    
    if(flag):
        print("found")
    else:
        print("not found")
    t-=1
        