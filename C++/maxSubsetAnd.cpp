#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int maximumSbstring(vector<int> &arr,int n){
    int maximum = *max_element(arr.begin(),arr.end());
    int tester = 1;
    int count = 0;
    while(tester <= maximum){
        int tempCount = 0;
        for(int i=0;i<n;i++){
            if(arr[i] & tester){
                tempCount++;
            }
        }
        count = max(tempCount,count);
        tester <<= 1;
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(5);
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maximumSbstring(arr,n) << endl;
}