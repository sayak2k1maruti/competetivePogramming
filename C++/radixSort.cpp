#include<iostream>
using namespace std;
#define radix 10
class queue{
    private:
        queue* front = NULL;
        queue* rear = NULL;
        queue* next = NULL;
        int data;
    public:
        void insert(int n);
        int retrieve();
        bool isEmpty();
};
int getMaximum(int arr[],int f,int r);
int numberOfDigits(int n);
void radixSort(int arr[],int f,int r);
void print(int *s,int* e);
int main(){
    int arr[] = {1,34,56,42,78,45,875,35,4,789,3,467567,86,908970,789,45767,78,678,4,46,6078,34,6,8,789,34,7,468,59,54,7};
    int size = sizeof(arr)/sizeof(int);

    cout << "Before:" << endl;
    print(arr,arr+size-1);

    radixSort(arr,0,size-1);

    cout << "After:" << endl;
    print(arr,arr+size-1);
} 
void radixSort(int arr[],int f,int r){
    if(f==r){
        return;
    }
    int count = numberOfDigits(getMaximum(arr,f,r));
    queue allDigits[radix];
    for(int z=1,place = 1;z<=count;z++,place *=10){
        for(int j=f;j<=r;j++){
            allDigits[(arr[j]/place)%10].insert(arr[j]);
        }
        //Now reconstruct the array
        int temp =0;
        for(int i=0;i<radix;i++){
            while(! allDigits[i].isEmpty()){
                arr[f+temp++] = allDigits[i].retrieve();
            }
        }
    }
}
int getMaximum(int arr[],int f,int r){
    int max = arr[f];
    for(int i=f+1;i<=r;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}
int numberOfDigits(int n){
    if(n<10)
        return 1;
    return 1 + numberOfDigits(n/10);
}
void queue::insert(int n){
    queue* temp  = (queue *)malloc(sizeof(queue));
    temp->data = n;
    temp->next =  NULL;
    if(front == NULL){
        front = temp;
        rear = temp;
    }else{
        rear->next = temp;
        rear = temp;
    }
}
int queue::retrieve(){
    if(front == rear){
        int temp = front->data;
        free(front);
        front = NULL;
        rear = NULL;
        return temp;
    }else{
        queue* temp = front;
        int n = front->data;
        front = front->next;
        free(temp);
        return n;
    }
}
bool queue::isEmpty(){
    if(front == NULL){
        return 1;
    }
    return 0;
}
void print(int* s,int* e){
    for(;s<=e;s++){
        cout<< *s << endl ;
    }
    cout << endl;
}