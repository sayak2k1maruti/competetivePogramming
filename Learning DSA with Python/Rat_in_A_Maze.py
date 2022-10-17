def solve(i,j,a,n,ans,move,vis,di,dj):
    if i==n-1 and j==n-1:
        ans.append(move)
        return
    dir='DLRU'
    for ind in range(n):
        nexti = i + di[ind]
        nextj = j + dj[ind]
        if nexti >= 0 and nextj >= 0 and nexti < n and nextj < n and not vis[nexti][nextj] and a[nexti][nextj] == 1:
            vis[i][j] = 1
            solve(nexti, nextj,a,n,ans,move+dir[ind],vis,di,dj)
            vis[i][j] = 0
ans=[]
n=4
m=[[1, 0, 0, 0],[1, 1, 0, 1],[1, 1, 0, 0],[0, 1, 1, 1]]
di=[+1,0,0,-1]
dj=[0,-1,1,0]
vis=[[0]*n for i in range(n)]
if m[0][0]==1:
    solve(0,0,m,n,ans,"",vis,di,dj)
print(' '.join(ans))
