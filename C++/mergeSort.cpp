#include<iostream>
void merge(int arr[],int l,int mid,int r);
void mergeSort(int arr[],int l,int r);
void print(int *s,int* e);
using namespace std;
int main(){
    int arr[] = {1,3,5,656,645,657,5,6346,56,5235,346,456,4563,26,546,256,357,34,67648466,7894,67356,73};
    int size = sizeof(arr)/sizeof(int);
    
    cout << "Before : "<<endl;
    print(arr,arr+size-1);
    cout << endl;

    mergeSort(arr,0,size-1);
    
    cout << "After :" << endl;
    print(arr,arr+size-1);
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid = (int)(l+r)/2;   l + (r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void merge(int arr[],int l,int mid,int r){
    int temp1[mid-l + 1];
    int temp2[r-mid];
    for(int i=0;i<mid-l+1;i++){
        temp1[i] = arr[l+i];
    }
    for(int i=0;i<r-mid;i++){
        temp2[i] = arr[mid+i+1];
    }
    int a=0,b=0;
    int index = l;
    for(;a<mid-l+1 && b<r-mid && index<=r;index++){
        if(temp1[a] < temp2[b]){
            arr[index] = temp1[a];
            a++;
        }else{
            arr[index] = temp2[b];
            b++;
        }
    }
    if(a<mid-l+1){
        for(;a<mid-l+1;a++){
            arr[index] = temp1[a];
            index++;
        }
    }
    if(b<r-mid){
        for(;b<r-mid;b++){
            arr[index] = temp2[b];
            index++;
        }
    }
}
void print(int* s,int* e){
    for(;s<=e;s++){
        cout<< *s << endl ;
    }
    cout << endl;
}