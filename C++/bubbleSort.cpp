#include<iostream>
void swap(int& a,int& b);
void bubbleSort(int arr[],int f,int r);
void print(int *s,int* e);
using namespace std;
int main(){
    int arr[] = {1,3,45,46,567,45,56,4,545,674,646,467,4,5,68,54,7,5};
    int size = sizeof(arr)/sizeof(int);

    cout << "Before:" << endl;
    print(arr,arr+size-1);

    bubbleSort(arr,0,size-1);

    cout << "After:" << endl;
    print(arr,arr+size-1);

}
void bubbleSort(int arr[],int f,int r){
    for(int i=r;i>=f;i--){
        for(int j=f+1;j<=i;j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}
void swap(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}
void print(int* s,int* e){
    for(;s<=e;s++){
        cout<< *s << endl ;
    }
    cout << endl;
}