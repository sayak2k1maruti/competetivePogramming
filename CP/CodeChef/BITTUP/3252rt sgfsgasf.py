import sys
t = int(input())
for _ in range(t):
    n,m=map(int,input().split())
    k=pow(2,n,1000000007)-1
    a=pow(k,m,1000000007)
    print(a)
