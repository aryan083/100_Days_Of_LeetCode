//884. Uncommon Words from Two Sentences
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word = s1 + " " + s2;

        unordered_map<string, int> map;
        string isWord = "";

        for (auto ch : word) { 
            if (ch == ' ') { 
                if (!isWord.empty()) { 
                    map[isWord]++;
                    isWord = "";
                }
            } else {
                isWord += ch; 
            }
        }

        if (!isWord.empty()) {
            map[isWord]++;
        }

        vector<string> result;
        for (const auto& entry : map) {
            if (entry.second == 1) { 
                result.push_back(entry.first); 
            }
        }

        return result;
    }
};