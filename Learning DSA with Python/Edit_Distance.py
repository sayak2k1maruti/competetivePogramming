"""
    EDIT DISTANCE

    Given two strings s1 and s2 and below operations that can be performed on s1.
    Find the minimum number of operations or edits required to convert s1 to s2.

    1. Insert
    2. Delete
    3. Modify

    Assumption : All of the operations are of equal cost.

    Example 1:  s1: "geek",  s2: "gesek"
    Output: 1
    We can convert s1 to s2 by inserting "s" in s1.

    Example 2:  s1: "cat",  s2: "cut"
    Output: 1
    We can convert s1 to s2 by modifying 'a' to 'u'.    

"""


#s1,s2="CART","MARCH"
s1=input()
s2=input()
row, col = (len(s1),len(s2))
arr = [[0 for i in range(col+1)] for j in range(row+1)]

for i in range(row+1):
    for j in range(col+1):
        if i==0 or j==0:
            arr[i][j]=max(i,j)
        elif s1[i-1]==s2[j-1]:
            arr[i][j]=arr[i-1][j-1]   #diagonal element 
        else:
            arr[i][j]=min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1])+1
                        # Remove,     Insert,     Replace

print(arr[row][col])    #Number of operations