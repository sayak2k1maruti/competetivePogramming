class Solution {
    public boolean isMatch(String s, String p) {
       boolean[][] dp = new boolean[p.length()+1][s.length()+1];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                //dp[0][0] value will be true because of empty string
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                //1st row will be false
                else if(i==0){
                    dp[i][j]=false;
                }
                // for 1st col we need to check for col-2 value if it is '*' else put false bcz '*' can be disappear also
                else if(j==0){
                    char pc = p.charAt(i-1);
                    if(pc=='*'){
                        dp[i][j]=dp[i-2][j];
                    }else{
                        dp[i][j]=false;
                    }
                }
                    else{
                       
                        char pc = p.charAt(i-1);
                        char sc = s.charAt(j-1);
        //if char is '*' or '.' then check for 2 uppr row or 1 col back value
                        if(pc=='*'){
                           dp[i][j]=dp[i-2][j];
                            char plsc = p.charAt(i-2);
                            if(plsc==sc || plsc=='.'){
                                 dp[i][j]=dp[i][j] || dp[i][j-1];
                            }
                //check if char is . then check previous diagonal value
                        }else if(pc=='.'){
                            dp[i][j]=dp[i-1][j-1];
                        }
                         //check if both char are same
                        else if(pc==sc){
                            dp[i][j]=dp[i-1][j-1];
                        }else{
                            dp[i][j]=false;
                        }
                    }
            }
        }
        return dp[p.length()][s.length()];
    }
}
