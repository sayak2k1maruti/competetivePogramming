class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = 1;
        int start=0;
        for(int i=0;i<n;i++)
        {
            int low=i-1;
            int high=i+1;

            while(high<n && s[high] == s[i])
                high++;
            while(low>=0 && s[low] == s[i])
                low--;
            while(high<n && low>=0 && s[high]==s[low])
            {
                high++;
                low--;
            }

            int length = high-low-1;
            if(length > maxLength)
            {
                maxLength = length;
                start=low+1;
            }
        }
        return s.substr(start, maxLength);
    }
};
