"""

    Write a function to take two parameters n and k and return the value of Binomial coefficient C(n,k).

    For example,
    =>  Given n=4 and k=2, return 6
    =>  Given n=5 and k=2, return 10

    The value of C(n,k) can be recursively calculated using following standard formula for Binomial coefficients:

    =>  C(n,k) = C(n-1,k-1) + c(n-1,k)
    =>  C(n,0) = C(n,n) = 1
    
"""
#n,k=4,2
n=int(input())
k=int(input())

row, col = n,k
arr = [[0 for i in range(col+1)] for j in range(row+1)]

def C(n,k):
    global arr
    if n==k or k==0:
        arr[n][k]=1
    elif arr[n][k]==0:
        arr[n-1][k-1]= arr[n-1][k-1] if arr[n-1][k-1]!=0 else C(n-1,k-1)
        arr[n-1][k]= arr[n-1][k] if arr[n-1][k]!=0 else C(n-1,k)
        arr[n][k]=arr[n-1][k-1]+arr[n-1][k]

    return arr[n][k]




print(C(n,k))