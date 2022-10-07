class Solution {
public:
    bool check(string &s , int l , int r){
        if(l >= r)
            return true;
        if(s[l] != s[r])
            return false;
        return check(s , l+1 , r-1);
    }
    string longestPalindrome(string s) {
        string ans = s.substr(0,1);
        for(int i = 0 ; i < s.length()-1 ; i++){
            int j = s.length() - 1;
            for(;(!check(s ,i , j )) && j>i && ans.length() < j - i + 1;j--);
            if(j - i + 1 > ans.length())
                ans = s.substr(i , j - i +1);
        }
        return ans;
    }
};
