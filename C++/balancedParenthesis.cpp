#include <bits/stdc++.h>
using namespace std;

bool isvalid(string s)
{
    int n = s.size();
    stack<char> st;

    bool ans = true;
    for (int i = 0; i < n; i++)
    {

        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
               return false;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
               return false;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
               return false;
            }
        }
    }
    if(!st.empty())  // means string is not empty
    {
        return false;
    }
    return true;

}

int main()
{
    string s ;
    cin>>s;

    if (isvalid(s))
        cout << " Balanced parenthesis";
    else
        cout << " UnBalanced parenthesis";
}