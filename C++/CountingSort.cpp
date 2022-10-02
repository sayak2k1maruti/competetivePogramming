#include <iostream>
#include <vector>

using namespace std;

vector <int> countingSort(vector <int> arr) {
    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    vector <int> count(max + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    vector <int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return output;
}

int main() {
    vector <int> arr = {1, 4, 1, 2, 7, 5, 2};
    vector <int> output = countingSort(arr);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}

//note that all elements in the array must be non-negative
// algorithm is only efficient when the range of input data is not significantly greater than the number of objects to be sorted
// time complexity: O(n + k)
