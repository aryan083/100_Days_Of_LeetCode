// 1310. XOR Queries of a Subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int arrsize = arr.size();
        vector<int> prefix(arrsize);
        vector<int> res(queries.size());

        prefix[0] = arr[0];
        for (int i = 1; i < arrsize; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0) {
                res[i] = prefix[right];
            } else {
                res[i] = prefix[right] ^ prefix[left - 1];
            }
        }

        return res;
    }
};