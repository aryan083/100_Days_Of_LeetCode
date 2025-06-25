class Solution {
public:
    string toHex(int num) {
        string ans  = "";
        string map = "0123456789abcdef";
        unsigned int num2 = num;
        if(num == 0) return "0";
        while( num2 ){
            int rem =  num2 & 15;
            ans = map[rem]+ans;
            num2=num2>>4;
        } 
        return ans;
    }
}; 