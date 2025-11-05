class Solution {
public:
    void helper(vector<int>&c ,int t,int index,vector<int>& comb,vector<vector<int>> &res,int total)  {
        if(total == t ){res.push_back(comb);return;}
        if(total>t || index >=c.size() )return;
        comb.push_back(c[index]);
        helper(c,t,index,comb,res,total+c[index]);
        comb.pop_back();
        helper(c,t,index+1,comb,res,total);
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        helper(candidates,target,0,comb,res,0);
        return res;
    }
};