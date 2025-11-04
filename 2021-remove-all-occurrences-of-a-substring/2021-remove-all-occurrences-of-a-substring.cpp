class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = ""; 
        int sSize = s.size();
        int partSize = part.size();

        for (int i = 0; i < sSize; ++i) {
            
            res.push_back(s[i]);

            if (res.size() >= partSize) {
                
                if (res.substr(res.size() - partSize, partSize) == part) {
                    
                    res.resize(res.size() - partSize);
                }
            }
        }        
        return res;
    }
};