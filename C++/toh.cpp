// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    private:
        int count = 0;
        void incrementCount(){
            this->count++;
        }
    public:
        long long toh(int N, int from, int to, int helper){
            if(N==0){
                return this->count;
            }
            toh(N-1,from,helper,to);
            cout << "move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            toh(N-1,helper,to,from);
            incrementCount();
            return this->count;
        }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends