class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		sort(num.begin(), num.end());
		set<vector<int> >rs;
		int n = num.size();
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				int p = j + 1;
				int q = n - 1;

				while (p < q) {
					int sum = num[i] + num[j] + num[p] + num[q];
					if (sum == target) {
						vector<int> tmp(4);
						tmp[0] = num[i];
						tmp[1] = num[j];
						tmp[2] = num[p];
						tmp[3] = num[q];
						rs.insert(tmp);
						p++;
						q--;
					} else if (sum < target) {
						p++;
					} else {
						q--;
					}
				}
			}
		}
		vector<vector<int> > result(rs.begin(), rs.end());
		return result;
    }
};
