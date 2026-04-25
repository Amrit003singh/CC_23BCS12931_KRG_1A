class Solution {
public:
    int find_ways(vector<int>& nums, int index, int target, int sum) {
        if (index == nums.size()) {
            return sum == target;
        }
        return find_ways(nums, index + 1, target, sum - nums[index]) +
               find_ways(nums, index + 1, target, sum + nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find_ways(nums, 0, target, 0);
    }
};
