class Solution:
def maxArea(self, height: List[int]) -> int:
    
    s = 0
    e = len(height)-1
    count = 0
    
    while s<e:
        temp = min(height[s],height[e])
        
        if count < temp*(e-s):
            count = temp*(e-s)
            
        if height[e]<height[s]:
            e-=1
        else:
            s+=1
    return count
