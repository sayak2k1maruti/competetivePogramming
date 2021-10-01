#include<iostream>
using namespace std;
int findMinIndex(int arr[],int f,int r){
    int min = f;
    for(;f<=r;f++){
        if(arr[f] < arr[min]){
            min = f;
        }
    }
    return min;
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[],int f,int r){
    int arrayLength = r - f;
    if(arrayLength < 1){
        return;
    }
    int minIndex = findMinIndex(arr,f,r);
    swap(arr[f],arr[minIndex]);
    selectionSort(arr,f+1,r);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    selectionSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}