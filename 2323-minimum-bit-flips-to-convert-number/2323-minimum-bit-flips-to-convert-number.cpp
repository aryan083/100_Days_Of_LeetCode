class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result=0;
        int num=start^goal;
        while (num){
            result+=num&1;
            num=num>>1;
           
        }
        return result;
    }
};