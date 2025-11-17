class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int major1=0,major2=0,counter1=0,counter2=0;
        for(int i : nums){
            if(i == major1)counter1++;
            else if(i ==major2)counter2++;
            else if (counter1==0){
                major1=i;counter1++;
            }
            else if(counter2==0){
                major2=i;counter2++;
            }
            else{counter1--;counter2--;}
        }
        counter1 =0;counter2 = 0;
        for(int i : nums){
            if(i ==major1)counter1++;
            else if( i == major2)counter2++;
        }    
 
        if(counter1>nums.size()/3)res.push_back(major1);

        if(counter2>nums.size()/3)res.push_back(major2);
        
        return res;
    }
};