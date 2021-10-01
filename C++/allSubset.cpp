#include<bits/stdc++.h>
using namespace std;
void allSubset(vector<int> arr,int  n){
    for(int subString = 0;subString < (1<<n) ; subString++){
        for(int j=0;j<n;j++){
            if(subString&(1<<j)){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    allSubset(arr,n);
    return 0;
}