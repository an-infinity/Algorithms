import heapq
def median(arr):
    minheap=[]    #for smaller half
    maxheap=[]    #for larger half
    heapq.heapify(minheap)
    heapq.heapify(maxheap)
    heapq.heappush(maxheap,-arr[0])
    med=arr[0]
    print(med)
    for i in range(1,len(arr)):
        x=arr[i]
        if(len(minheap)<len(maxheap)):
            if(x<med):
                y=-heapq.heappop(maxheap)
                heapq.heappush(maxheap,-x)
                heapq.heappush(minheap,y)
            else:
                heapq.heappush(minheap,x)
            med=(minheap[0]-maxheap[0])//2
                
        elif(len(minheap)==len(maxheap)):
            if(x<med):
                heapq.heappush(maxheap,-x)
                med=-maxheap[0]
            else:
                heapq.heappush(minheap,x)
                med=minheap[0]
        
        else:
            if(x>med):
                y=heapq.heappop(minheap)
                heapq.heappush(minheap,x)
                heapq.heappush(maxheap,-y)
            else:
                heapq.heappush(maxheap,-x)
            
            med=(minheap[0]-maxheap[0])//2
        
        print(med)

t=int(input())
A=[]
while(t):
    A.append(int(input()))
    t-=1

if(len(A)==1):
    print(A[0])
else:
    median(A)
        
            
            
            
            
    
    
    