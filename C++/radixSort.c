#include<stdio.h>
#include<stdlib.h>
#define radix 10
typedef struct queue{
    int data;
    struct queue* next;
}queue;
void insert(int n,queue** front,queue** rear);
int retrieve(queue** front,queue** rear);
void radixSort(int arr[],int f,int r);
queue* createNode(int n);
int maxnumber(int arr[],int f,int r);
int countDigits(int n);
void print(int* f,int* l);
int main(){
    int arr[] = {1,34,56,42,78,45,875,35,4,789,3,467567,86,908970,789,45767,78,678,4,46,6078,34,6,8,789,34,7,468,59,54,7};
    int size = sizeof(arr)/sizeof(int);

    printf("Before:\n");
    print(arr,arr+size-1);
    radixSort(arr,0,size-1);

    printf("After\n");
    print(arr,arr+size-1);
}
void radixSort(int arr[],int f,int r){
    queue* digits[radix][2]; /*digits[index] = {front,rear ... of queue at index "index"} */
    int count = countDigits(maxnumber(arr,f,r));
    int i,place=1,j,temp,k,z;
    
    for(z=0;z<radix;z++){
        digits[z][0] = NULL;
        digits[z][1] = NULL;
    }   
    for(i=0,place=1;i<count;i++,place*=10){
        for(j=f;j<=r;j++){
            insert(arr[j],&digits[(arr[j]/place)%10][0],&digits[(arr[j]/place)%10][1]);
        }
        //Now reconstructing the array
        temp = 0;
        for(k=0;k<radix;k++){
            while(digits[k][0] != NULL){
                int a = retrieve(&(digits[k][0]),&(digits[k][1]));
                arr[f+temp++] =a ;
            }
        }
     }
}
void insert(int n,queue** front,queue** rear){
    queue* temp = createNode(n);
    if((*front) == NULL){
        
        (*front) = temp;
        (*rear) = temp;
    }
    (*rear)->next = temp;
    (*rear) = temp;
}
int retrieve(queue** front,queue** rear){
    queue* temp = (*front);
    int n = (*front)->data;
    if((*front) == (*rear)){
        (*front) = NULL;
        (*rear) = NULL;
    }else{
        (*front) = temp->next;
    }
    free(temp);
    return n;
}
queue* createNode(int n){
    queue* temp = (queue *)malloc(sizeof(queue));
    temp->data = n;
    temp->next = NULL;
    return temp;
}
int maxnumber(int arr[],int f,int r){
    int max = arr[f];
    for(f++;f<=r;f++){
        if(arr[f]>max) 
            max = arr[f];
    }
    return max;
}
int countDigits(int n){
    if(n < 10){
        return 1;
    }
    return 1 + countDigits(n/10);
}
void print(int* f,int* l){
    for(;f<=l;f++){
        printf("%d\n",*f);
    }
}