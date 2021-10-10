/*
Given an array = {1,2,3,4}, and a number = k = 8
find if we can found a subset like that,
sum of all element of that subset  is = k 

subset = {1,3,4} = sum = 8 = k : return true
*/
#include"bits/stdc++.h"
using namespace std;
bool findSubsetSum(vector<int>& arr,int sum,int n,vector<vector<int>>& memory){
    if(memory[sum][n] != -1){
        return memory[sum][n];
    }
    if(sum == 0){
        memory[sum][n] = 1;
        return true;
    }
    if(n == 0 && sum != 0){
        memory[sum][n] = 0;
        return false;
    }
    if(arr[n-1] > sum){
        memory[sum][n] = findSubsetSum(arr,sum,n-1,memory);
        return memory[sum][n];
    }
    memory[sum][n] = findSubsetSum(arr,sum,n-1,memory) || findSubsetSum(arr,sum - arr[n-1],n-1,memory);
    return memory[sum][n];
}
int main(){
    int t;cin >> t;
    for(;t>0;t--){
        int n,sum;cin >> n >> sum;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<vector<int>> memory(sum+1,vector<int>(n+1,-1));
        cout << (findSubsetSum(arr,sum,n,memory) ? "Yes" : "No") << endl;
    }
    return 0;
}
