#include"bits/stdc++.h"
#define ll long long int
using namespace std;
ll det(vector<vector<ll>> &matrix,int n){
    if(n==1){
        return matrix[0][0];
    }
    ll ans = 0;
    int sign = 1;
    for(int c=0;c<n;c++){
        vector<vector<ll>> tempMatrix(n-1,vector<ll>(n-1));
        for(int r=1;r<n;r++){
            int rowPos = 0;
            for(int cc=0;cc<n;cc++){
                if(cc == c){
                    continue;
                }
                tempMatrix[r-1][rowPos++] = matrix[r][cc];
            }
        }
        ans += matrix[0][c] * det(tempMatrix,n-1) * sign;
        sign *= -1;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector <vector<ll>> arr(n,vector<ll>(n));
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    cout <<  det(arr,n) << endl;
    cout << 0xAAAAAAAA;
    return 0;
}