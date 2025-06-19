class Solution {
public:
    int alternateDigitSum(int n) {
        int AltSum=0, temp, sign=1;
        while(n!=0){
            temp=n%10;
            sign*=-1;
            AltSum+=temp*sign;
            n/=10;
        } 
        return sign*AltSum;

    }
};