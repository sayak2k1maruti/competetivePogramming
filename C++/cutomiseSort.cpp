/*
How to sort a string according to it's size()
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    vector <string> names;
    cout << "Total number of String : ";
    cin >> t;
    for(;t>0;t--){
        string temp;
        cin >> temp;
        names.push_back(temp);
    }

    //Sorting....
    sort(names.begin(),names.end(),[](auto first,auto second) -> bool{
        return first.size() > second.size();
    });

    cout<<endl << endl;

    //Printing ...
    for(auto it = names.begin();it < names.end();it++){
        cout << *it << ' '<< (*it).size() <<'\n';
    }

    return 0;
}