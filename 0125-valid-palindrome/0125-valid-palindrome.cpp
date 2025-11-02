class Solution {
public:
    bool isPalindrome(string s) {
        string clear="";
        for(char c : s){
            if(isalnum(c))clear+=tolower(c);

        }
        int l=0,r=clear.size()-1;
        while(l<=r){
            if(clear[l]!=clear[r])return false;
            l++;r--;
        }
        cout<<"ans"<<clear;
        return true;
    }
};