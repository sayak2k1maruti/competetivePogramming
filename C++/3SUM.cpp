#include<bits/stdc++.h>
using namespace std; 
void threeSum(vector<int>&arr,int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        int low = i+1;
        int high = n-1;
        while(low < high){
            int tempSum = arr[i] + arr[low] + arr[high];
            if(tempSum == target){
                cout<<"3 sum Found :" << arr[i] << "+" << arr[low]<< "+" << arr[high] <<endl;
                return;
            }else if(tempSum > target){
                high--;
            }else{
                low++;
            }
        }
    }
    cout << "3 sum not found" << endl;
}
int32_t main(){
    vector <int> arr = {1,4,3,0,4,56,7,4,6,8,434,7,9,6,4,3,7,97,54,4,7,8};
    int target = 8;
    threeSum(arr,target);
    return 0;
}