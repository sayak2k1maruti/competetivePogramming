#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector <int> arr,int begin,int end,int number){
    if(begin < end){
        int mid = (begin+end)/2;
        if(arr[mid] == number){
            return mid;
        }else if(arr[mid] > number){
            return binarySearch(arr,begin,mid,number);
        }else{
            return binarySearch(arr,mid+1,end,number);
        }
    }
    return -1;
}
int main(){
    vector <int> arr{2,3,4,69,120,155,178,990};
    int size = arr.size();
    cout << binarySearch(arr,0,size - 1,2) << endl;
    cout << binarySearch(arr,0,size - 1,3) << endl;
    cout << binarySearch(arr,0,size - 1,4) << endl;
    cout << binarySearch(arr,0,size - 1,55) << endl;
    cout << binarySearch(arr,0,size - 1,45) << endl;
    cout << binarySearch(arr,0,size - 1,69) << endl;
    return 0;
}