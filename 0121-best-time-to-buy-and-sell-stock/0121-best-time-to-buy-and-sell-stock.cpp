class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin=prices[0],res=0;
        for(int i =1; i < prices.size();i++){
            currMin= min(currMin,prices[i]);
            res=max(res,prices[i]-currMin);
        }
        return res;

    }
};