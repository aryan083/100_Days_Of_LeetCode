#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());               // 1) sort to handle duplicates & pruning
        backtrack(candidates, target, 0, path, result);
        return result;
    }

private:
    void backtrack(const vector<int>& cand, int remain, int start,
                   vector<int>& path, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < (int)cand.size(); ++i) {
            // 2) skip duplicates at the same recursion level
            if (i > start && cand[i] == cand[i - 1]) continue;

            // 4) pruning (since sorted)
            if (cand[i] > remain) break;

            path.push_back(cand[i]);            // choose
            backtrack(cand, remain - cand[i], i + 1, path, result); // use i+1 because each element can be used once
            path.pop_back();                    // backtrack
        }
    }
};

// Example usage (not required on LeetCode; shown for local testing)
/*
int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    auto res = s.combinationSum2(candidates, target);
    for (auto &comb : res) {
        for (int x : comb) cout << x << ' ';
        cout << '\n';
    }
}
*/
