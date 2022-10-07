class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict={}
        max_num=0
        count=0
        for index, val in enumerate(s):
            if val not in dict:
                dict[val]=index
                count+=1
                max_num=max(max_num,count)
            else:
                num=index-dict[val]
                if num>count:
                    count+=1
                    max_num=max(max_num,count)
                else:
                    count=num
                dict[val]=index
        return max_num
