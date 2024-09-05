// 2028. Find Missing Observations
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int rollsum=accumulate(rolls.begin(),rolls.end(), 0);
        int missingSum=mean*(n+m)-rollsum;

        if( missingSum  > 6*n  || missingSum < n)
            return vector<int> ();
        
        vector<int> result;
        int dice;
        while(n){
            dice=min(6,missingSum-(n-1));
            result.push_back(dice);
            missingSum-=dice;
            n--;
        }
        return result;

        

    }
};