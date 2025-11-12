class Solution {
private:
    void update_count(vector<char> &chars, int &index, int &count) {
    if (count > 1) {
            string num = to_string(count);
            for(char c : num) {
                chars[index++] = c;
            }
        }
        count = 1;
    }
public:
    int compress(vector<char>& chars) {
        int i = 1, n = chars.size(), index = 0;
        char c = chars[0];
        int count = 1;
        while(i < n) {
            if (chars[i] == c) {
                count++;
            }
            else {
                chars[index++]=c;
                update_count(chars, index, count);
                c = chars[i];
            }
            // while(i < n && chars[i] == c) {
            //     i++;
            //     count++;
            // }
        i++;
        }
        chars[index++] = c; 
        update_count(chars, index, count);
        // chars.resize(index);
        return index;
    }
};