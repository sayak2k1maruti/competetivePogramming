#include<iostream>
using namespace std;
class stack{
    private:
        stack* top = NULL;
        int data;
        stack* next;
    public:
        stack* push(int n);
        int pop();
        void print();
};
int main(){
    stack sayak;
    bool flag = 1;
    while(flag){
        char temp;
        cout << "<1> for push <2> for pop <3> for print <any other> for exit: ";
        cin >> temp;
        switch (temp){
            case '1' : cout<<"Int to push : ";
                       int nn;
                        cin >> nn;
                        if(sayak.push(nn) == NULL)  cout << "Cann't push";
                        break;
            case '2': cout << sayak.pop();
                      break;
            case '3': sayak.print();
                      break;
            default:  flag = 0;
        }
    }    
}

stack* stack::push(int n){
    stack* temp = (stack *)malloc(sizeof(stack));
    if(temp == NULL){
        return NULL;
    }
    temp ->data = n;
    temp -> next = (top == NULL)?NULL:top;
    top = temp;
    return temp;
}

int stack::pop(){
    if(top == NULL){
        cout << "Stack Empty";
        return 0;
    }
    stack* temp = top;
    top = temp->next;
    int n = temp->data;
    free(temp);
    return n;
}
void stack::print(){
    cout <<endl;
    if(top == NULL){
        cout << "Empty stack....";
    }
    for(auto it = top;it != NULL;it = it -> next){
        cout << it->data <<"<--" ;
    }
    cout <<endl;
}