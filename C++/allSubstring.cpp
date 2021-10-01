#include"bits/stdc++.h"
using namespace std;
void subset(string s){
    for(int i=0;i<s.length();i++){
        for(int j=s.length();j>i;j--){
            cout << s.substr(i,j) << endl;
        }
    }
}
int main(){
    string s;cin >> s;subset(s);return 0;
}