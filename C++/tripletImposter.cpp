#include<bits/stdc++.h>
using namespace std;
bool getbit(int a,int pos){
    return ((a & (1<<pos)) != 0);
}
int findTripletImposter(vector<int> arr,int n){
    vector <int> bits(64,0);
    for(int pos =0;pos<64;pos++){
        for(int i=0;i<n;i++){
            if(getbit(arr[i],pos)){
                bits[pos]++;
            }
        }
    }
    int ans = 0;
    for(int i=63;i>=0;i--){
        ans <<= 1;
        ans += (bits[i] % 3)% 2;  
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << findTripletImposter(arr,n) << endl;
    return 0;
}