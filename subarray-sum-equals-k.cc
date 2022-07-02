class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            [1, 1, 1] k = 3 -> 2
            [1, 2, 3] k = 3  
        */
        std::unordered_map<int, int> map;
        int currSum = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (currSum == k) {
                res++;
            }
            if (map.find(currSum - k) != map.end()) {
                res += map[currSum - k];
            }
            map[currSum]++;
        }

        return res;
    }
};
