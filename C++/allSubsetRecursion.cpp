#include"bits/stdc++.h"
using namespace std;
class allSubset{
    private:
        void subsets(string &S,int f,int r,string temp){
            if(f>r){
                cout << temp << endl;
                return;
            }
            subsets(S,f+1,r,temp); //S[i] Thakbe na
            subsets(S,f+1,r,temp+S[f]); //S[i] thakbe
        }
    public:
        void printAllSubset(string &S){
            this->subsets(S,0,S.length()-1,"");
        }
};
int main(){
    allSubset ob;string S;cin >> S;ob.printAllSubset(S);return 0;
}