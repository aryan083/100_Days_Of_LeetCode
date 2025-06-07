class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>entry_count;
        for(auto &num:arr)entry_count[num]++;

        unordered_set<int>freqency;
        for(auto& [v,f]: entry_count){
            if(freqency.count(f)!=0)return false;
            freqency.insert(f);

        }
        return true;

        
    }
};