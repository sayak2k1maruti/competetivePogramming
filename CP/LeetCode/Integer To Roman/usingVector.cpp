class Solution {
public:
    string intToRoman(int num) 
    {
      //create a value vector of type int and store the values
        vector<int> value={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> notations={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string roman="";
      
      //iterate all over the vector
        for(int pos=0;num>0;pos++)
        {
            while(num>=value[pos])
            {
                roman=roman+notations[pos];
                num=num-value[pos];
            }
        }
        return roman;
    }
};
