class Solution {
public:
    string intToRoman(int num) {
        int rem = 0, pos = 0;
        vector<string> sym = {"I" , "V" , "X" , "L" , "C" , "D" , "M"};
        string ans = "";
        while(num){
            rem = num % 10;
            switch (rem){
                case 1:
                    ans = sym[pos] + ans;
                    break;
                case 2:
                    ans = sym[pos]+sym[pos]+ ans;
                    break;
                case 3:
                    ans = sym[pos]+sym[pos]+sym[pos] + ans;
                    break;
                case 4:
                    ans = sym[pos]+sym[pos+1]+ans;
                    break;
                case 5:
                    ans = sym[pos+1]+ans;
                    break;
                case 6:
                    ans = sym[pos+1]+sym[pos]+ans;
                break;
                case 7:
                    ans = sym[pos+1]+sym[pos]+sym[pos]+ans;
                break;
                case 8:
                    ans = sym[pos+1]+sym[pos]+sym[pos]+sym[pos]+ans;
                break;
                case 9:
                    ans = sym[pos]+sym[pos+2]+ans;
                break;
              default:
                    ans = ans;
            }
            pos += 2;
            num = num / 10;
        }
        return ans;
    }
};