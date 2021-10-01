#include<bits/stdc++.h>
using namespace std;
bool sortByName(pair<int,string> a,pair<int,string> b){
    int aLen = a.second.length();
    int bLen = b.second.length();
    for(int i=0;i<aLen || i<bLen ; i++){
        if(b.second[i] < a.second[i]){
            return false;
        }else if(b.second[i] > a.second[i]){
            return true;
        }
    }
    if(bLen<aLen){
        return false;
    }
    return true;
}
void printAll(vector<pair<int,string>> &arr){
    for(auto element : arr){
        cout << element.first << "\t\t" << element.second << endl;
    }
}
bool sortByRoll(pair<int,string> a,pair<int,string> b){
    if(a.first > b.first){
        return false;
    }
    return true;
}
int32_t main(){
    vector <pair<int,string>> students;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int roll;
        string name;
        cin >> roll >> name;
        students.push_back(make_pair(roll,name));
    }
    sort(students.begin(),students.end(),sortByName);
    cout << " Students sorted by name:" << endl;
    printAll(students);
    //
    sort(students.begin(),students.end(),sortByRoll);
    cout << " Students sorted by Roll:" << endl;
    printAll(students);
    return 0;
}