#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkRepetition(string& s, int start, int end) {
    vector<int> chars(128);

    for (int i = start; i <= end; i++) {
        char c = s[i];
        chars[c]++;
        if (chars[c] > 1) {
            return false;
        }
    }

    return true;
}

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}


int main() {
    // Your code goes here;
    string s = "Hello";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
