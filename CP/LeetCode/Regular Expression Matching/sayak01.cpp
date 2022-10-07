#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string& s , string &p , int si , int pi){
        if(pi < 0 && si < 0){
            return true;
        }
        if(pi < 0 && si >= 0)
            return false;
        if(pi >= 0 && si < 0 ){
            if(p[pi] == '*')
                return isMatch(s , p , si , pi - 2);
            else
                return false;
        }
        if(p[pi] != '*'){
            return isMatch(s,p,si-1,pi-1) && ((s[si]==p[pi]) || (p[pi]=='.'));
        }else if((s[si] == p[pi-1]) || (p[pi-1] == '.')){
            return isMatch(s , p , si , pi - 1) || isMatch(s,p,si-1,pi) || isMatch(s , p , si  , pi - 2);
        }else{
            return isMatch(s , p , si  , pi - 2);
        }
    }
    bool isMatch(string s, string p) {
        return isMatch(s , p , s.length() -1  , p.length() - 1);
    }
};
