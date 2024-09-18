// 179. Largest Number

class Solution {
public:
   static bool compareString(int num1,int num2){
        return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
        
    }
    string largestNumber(vector<int>& nums) {   
        sort(nums.begin(),nums.end(),compareString);
        if(nums[0] == 0 ) return "0";
        
        string res;
        for(auto i :nums) res+=to_string(i);
        return res;
    }
};