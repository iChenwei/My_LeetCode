// 数组 二分
/*
    思路：
        - 利用单调性，找左端点和右端点
    注意：
        - 如果有变量重复使用，需要及时保存
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};  // 特判
        // 找左端点
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[l] != target) return {-1, -1};

        int res_l = l; // 记录左端点
        // 找右端点
        l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return {res_l, r};
    }
};