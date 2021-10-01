#include<bits/stdc++.h>
using namespace std;
bool getBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
void findTwoImposter(vector<int> arr, int n){
    int xorAll = 0;
    for(auto element:arr){
        xorAll ^= element;
    }
    //finding position of first left one of xorAll
    int pos = 0;
    int setBit = 0;
    while(setBit != 1){
        setBit = 1 & xorAll;
        xorAll >>= 1;
        pos++;
    }
    int a=0,b=0;
    for(auto element : arr){
        if(getBit(element,pos-1)){
            a ^= element;
        }else{
            b ^= element;
        }
    }
    cout << a << " " << b << endl;
}
int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    findTwoImposter(arr,n);
    return 0;
}