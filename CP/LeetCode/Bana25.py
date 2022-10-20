class Solution:
    def intToRoman(self, num: int) -> str:
        r={1000:"M",500:"D",100:"C",50:"L",10:"X",5:"V",1:"I"}
        s=""
        for i in r:
            n=num//i 
            s=s+r[i]*n 
            num=num%i 
        x=s.replace("DCCCC","CM")
        s=x.replace("CCCC","CD")
        x=s.replace("LXXXX","XC")
        s=x.replace("XXXX","XL")
        x=s.replace("VIIII","IX")
        s=x.replace("IIII","IV")
        return s 
