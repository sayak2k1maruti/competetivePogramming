#include<iostream>
using namespace std;
void quickSort(int arr[],int f,int r);
void print(int *s,int* e);
void swap(int& a,int& b);
int main(){
    int array[] = {3424,345,6,46,47,568,5,236,567,56,85,7,78,32,2,3,769,9,46,87,695,6};
    int size = sizeof(array)/sizeof(int);

    cout << "Before : "<<endl;
    print(array,array+size-1);
    cout << endl;

    quickSort(array,0,size-1);
    
    cout << "After :" << endl;
    print(array,array+size-1);
    return 0;
}
void quickSort(int arr[],int f,int r){
    if(f>=r){
        return;
    }
    int outPut[r-f+1];
    cout << r-f+1 << endl;
    int front = 0;
    int rear = r-f;
    for(int i=1;i<=r-f;i++){
        //cout << i << endl;
        if(arr[f+i] > arr[f]){
            outPut[rear--] = arr[f+i];
        }else{
            outPut[front++] = arr[f+i];
        }
    }

    outPut[front] = arr[f];
    for(int i=0;i<=r-f;i++){
        arr[f+i] = outPut[i];
        //cout << outPut[i] << " ";
    }
    quickSort(arr,f,f+front-1);
    quickSort(arr,f+front+1,r);
}
void swap(int&a ,int& b){
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