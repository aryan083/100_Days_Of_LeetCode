class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPartitions(nums, mid) > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    int countPartitions(const vector<int>& nums, int maxSumAllowed) {
        int count = 1, total = 0;
        for (int num : nums) {
            if (total + num > maxSumAllowed) {
                count++;
                total = num;
            } else {
                total += num;
            }
        }
        return count;
    }
};