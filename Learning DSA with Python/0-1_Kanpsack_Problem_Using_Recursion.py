"""
    0-1 Knapsack Problem

    Given weights and values of n items, put these items in a knapsack of capacity W 
    to get the maximum total value in the knapsack. 
    
    In other words, 
    Given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights .
    Also given an integer W which represents knapsack capacity.
    Find maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
    
    0-1 Property: You cannot break an item, either pick the complete item or don’t pick it.

    value[]={60,100,120}    Value of individual item
    weight[]={10,20,30}     Weight of individual item
    W=50                    Maximum allowed weight
    Solution:   220         Max value possible, keeping weight <=50

    Using Recursion:
        Time Complexity: O(2^N)
        Space Complexity: O(1)
"""

def knapsack(W,val,weight,n):
    if n==-1 or W==0 :#No element or no weight left
        return 0
    elif weight[n]>W:   #If nth item doesn't meet weight constrain
        return knapsack(W,val,weight,n-1)
    else:
        return max(val[n]+knapsack(W-weight[n],val,weight,n-1),
        knapsack(W,weight,val,n-1))
        #Returns the max values from 2 subsets: 1 including nth item, 2 excluding nth item


v=[60,100,120]    #Value of individual item
w=[10,20,30]     #Weight of individual item
wt=50  

print(knapsack(wt,v,w,2))   #n=2, cuz 0,1,2