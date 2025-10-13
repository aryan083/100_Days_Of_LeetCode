typedef unordered_map<int,int> umii;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i =1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        // int i =0,j=1
        // vector<int> answer;
        // sum[from i to j] = prefix[j]-prefix[i];
        // int count=0;
        // bool wholeArray = prefix[nums.size()-1]==k ? true : false;
        // for(int i =0;i<nums.size();i++){
        //     for(int j =i+1;j<nums.size();j++){
        //         if(prefix[j]==k || prefix[i]==k)count++;
        //         if(abs(prefix[i]-prefix[j])==k)count++;
        //     }
        // }
        // if(wholeArray)count++;
        // return count;

        umii m;
        int ans=0;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==k)ans++;
        
            if(m.find(prefix[i]-k)!=m.end()){
                ans+=m[prefix[i]-k];
            }
            m[prefix[i]]++;
        }

    return ans;

    }
};