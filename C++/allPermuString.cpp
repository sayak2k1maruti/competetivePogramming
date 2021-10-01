#include"bits/stdc++.h"
using namespace std;

class Solution{
    private:
        void permute(string S,string ans,vector<string> &arr){
            if(S.length () == 0){
                arr.push_back(ans);
                return; 
            }
            for(int i=0;i<S.length();i++){
                string leftSide = S.substr(0,i);
                string rightSide = S.substr(i+1);
                this->permute(leftSide+rightSide,ans+S[i],arr);
            }

        }
	public:
		vector<string>find_permutation(string S){
            sort(S.begin(),S.end());
            vector<string> permutations;
            this->permute(S,"",permutations);
            return permutations;
		}
};

int main(){
    string S;
	cin >> S;
	Solution ob;
	vector<string> ans = ob.find_permutation(S);
	for(auto i: ans){
	    cout<<i<<" "<<endl;
	}
	cout<<"\n";
	return 0;
}