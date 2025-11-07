class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        map<int ,int>mp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        auto it = mp.rbegin();
        ans.push_back(it->first);
        int remove = 0;
        for(int i=k;i <nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[remove]]==1){
                mp.erase(nums[remove]);
            }else{
                mp[nums[remove]]--;
            }
            remove++;
            auto it = mp.rbegin();
            ans.push_back(it->first);
        }
        return ans;
    }
};