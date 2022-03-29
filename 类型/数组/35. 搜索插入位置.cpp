// 数组 二分
/*
    思路：
        - 根据样例写出check(mid)
    注意：
        - 可以插入的位置决定了初始边界
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};