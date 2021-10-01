#include<iostream>
using namespace std;
void swap(int& a,int& b){
    int c = a;
    a = b;
    b = c;
}
int main(){
    int arr[] = {1,2,1,2,2,1,0,0,1,0,2,1,1,0};//array of only 0,1,2
    int n = sizeof(arr)/sizeof(int);
    int low = 0;
    int mid = 0;
    int high = n-1;
    for(;mid<=high;){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<  " ";
    }
    return 0;
}